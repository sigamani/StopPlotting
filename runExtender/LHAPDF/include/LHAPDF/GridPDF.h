// -*- C++ -*-
//
// This file is part of LHAPDF
// Copyright (C) 2012-2014 The LHAPDF collaboration (see AUTHORS for details)
//
#pragma once
#ifndef LHAPDF_GridPDF_H
#define LHAPDF_GridPDF_H

#include "LHAPDF/PDF.h"
#include "LHAPDF/Interpolator.h"
#include "LHAPDF/Extrapolator.h"
#include "LHAPDF/KnotArray.h"

namespace LHAPDF {


  /// @brief A PDF defined via an interpolation grid
  class GridPDF : public PDF {
  public:

    /// @name Creation and deletion
    //@{

    /// @brief Constructor from a file path.
    ///
    /// We allow this to exist and be user-callable for testing and other
    /// special case uses, since if you are explicitly instantiating a GridPDF
    /// rather than acquiring it via a pointer/reference of PDF type, then you
    /// probably (hopefully) know what you're doing and aren't putting it into
    /// public production code!
    GridPDF(const std::string& path) {
      _loadInfo(path); // Sets _mempath
      _loadData(_mempath);
      _forcePos = -1;
    }

    /// Constructor from a set name and member ID.
    GridPDF(const std::string& setname, int member) {
      _loadInfo(setname, member); // Sets _mempath
      _loadData(_mempath);
      _forcePos = -1;
    }

    /// Constructor from a set name and member ID.
    GridPDF(int lhaid) {
      _loadInfo(lhaid); // Sets _mempath
      _loadData(_mempath);
      _forcePos = -1;
    }

    /// Virtual destructor to allow inheritance.
    virtual ~GridPDF() { }

    //@}


  protected:

    /// Load the PDF grid data block (not the metadata) from the given PDF member file
    void _loadData(const std::string& mempath);


  public:

    /// @name Interpolators and extrapolators
    //@{

    /// @brief Set the interpolator by pointer
    ///
    /// The provided Interpolator must have been new'd, as it will not be copied
    /// and ownership passes to this GridPDF: delete will be called on this ptr
    /// when this GridPDF goes out of scope or another setInterpolator call is made.
    void setInterpolator(Interpolator* ipol) {
      _interpolator.reset(ipol);
      _interpolator->bind(this);
    }

    /// @brief Set the interpolator by value
    ///
    /// The passed value must be a concrete instantiation of the Interpolator
    /// interface. It will be copied and heap-assigned for use inside this GridPDF.
    ///
    /// @todo Use SFINAE magic to restrict INTERPOLATOR to subclasses of Interpolator?
    template <typename INTERPOLATOR>
    void setInterpolator(INTERPOLATOR ipol) {
      setInterpolator(new INTERPOLATOR(ipol));
    }

    /// @brief Set the interpolator by name
    ///
    /// Use the interpolator specified by the given name, as passed to the
    /// createInterpolator factory function.
    void setInterpolator(const std::string& ipolname) {
      setInterpolator(mkInterpolator(ipolname));
    }

    /// Find whether an extrapolator has been set on this PDF
    bool hasInterpolator() const {
      return _interpolator.get() != 0;
    }

    /// Get the current interpolator
    const Interpolator& interpolator() const {
      if (_interpolator.get() == 0) { // Load the default interpolator lazily
        // NB. The following is equiv to set-by-name but is explicitly implemented here for const correctness
        const string ipolname = info().get_entry("Interpolator");
        Interpolator* ipol = mkInterpolator(ipolname);
        _interpolator.reset(ipol);
        _interpolator->bind(this);
      }
      return *_interpolator;
    }



    /// @brief Set the extrapolator by pointer
    ///
    /// The provided Extrapolator must have been new'd, as it will not be copied
    /// and ownership passes to this GridPDF: delete will be called on this ptr
    /// when this GridPDF goes out of scope or another setExtrapolator call is made.
    void setExtrapolator(Extrapolator* xpol) {
      _extrapolator.reset(xpol);
      _extrapolator->bind(this);
    }

    /// @brief Set the extrapolator by value
    ///
    /// The passed value must be a concrete instantiation of the Extrapolator
    /// interface. It will be copied and heap-assigned for use inside this GridPDF.
    ///
    /// @todo Use SFINAE magic to restrict EXTRAPOLATOR to subclasses of Extrapolator?
    template <typename EXTRAPOLATOR>
    void setExtrapolator(EXTRAPOLATOR xpol) {
      setExtrapolator(new EXTRAPOLATOR(xpol));
    }

    /// @brief Set the extrapolator by name
    ///
    /// Use the extrapolator specified by the given name, as passed to the
    /// createExtrapolator factory function.
    void setExtrapolator(const std::string& xpolname) {
      setExtrapolator(mkExtrapolator(xpolname));
    }

    /// Find whether an extrapolator has been set on this PDF
    bool hasExtrapolator() const {
      return _extrapolator.get() != 0;
    }

    /// Get the current extrapolator
    const Extrapolator& extrapolator() const {
      if (_extrapolator.get() == 0) { // Load the default extrapolator lazily
        // NB. The following is equiv to set-by-name but is explicitly implemented here for const correctness
        const string xpolname = info().get_entry("Extrapolator");
        Extrapolator* xpol = mkExtrapolator(xpolname);
        _extrapolator.reset(xpol);
        _extrapolator->bind(this);
      }
      return *_extrapolator;
    }

    //@}


  protected:

    /// @brief Get PDF xf(x,Q2) value (via grid inter/extrapolators)
    double _xfxQ2(int id, double x, double q2) const;


  public:

    /// @name Info about the grid, and access to the raw data points
    //@{

    /// Get the N-flavour subgrid containing Q2 = q2
    const KnotArrayNF& subgrid(double q2) const {
      assert(q2 >= 0);
      map<double, KnotArrayNF>::const_iterator it = _knotarrays.upper_bound(q2);
      if (it == _knotarrays.begin()) throw GridError("Requested Q2 is lower than any available Q2 subgrid");
      if (it == _knotarrays.end() && q2 > q2Knots().back()) throw GridError("Requested Q2 is higher than any available Q2 subgrid");
      --it; // upper_bound (and lower_bound) returns the entry *above* q2: we need to decrement by one element
      // std::cout << "Using subgrid #" << std::distance(_knotarrays.begin(), it) << std::endl;
      return it->second;
    }

    /// Get the 1-flavour subgrid for PID=id containing Q2 = q2
    const KnotArray1F& subgrid(int id, double q2) const {
      return subgrid(q2).get_pid(id);
    }

    /// @brief Return a representative list of interpolation knots in x
    ///
    /// The x knot array for the first flavor grid of the lowest-Q2 subgrid is returned.
    const vector<double>& xKnots() const {
      const KnotArrayNF& subgrid1 = _knotarrays.begin()->second;
      const KnotArray1F& grid1 = subgrid1.get_first();
      return grid1.xs();
    }

    /// @brief Return a representative list of interpolation knots in Q2
    ///
    /// Constructed and cached by walking over all subgrids and concatenating their Q2 lists.
    const vector<double>& q2Knots() const {
      if (_q2knots.empty()) {
        // Get the list of Q2 knots by combining all subgrids
        /// @todo Roll on C++11... range-based for and auto :-)
        for (map<double, KnotArrayNF>::const_iterator isub = _knotarrays.begin(); isub != _knotarrays.end(); ++isub) {
          const KnotArrayNF& subgrid = isub->second;
          const KnotArray1F& grid1 = subgrid.get_first();
          if (grid1.q2s().empty()) continue;
          BOOST_FOREACH (const double& q2, grid1.q2s()) {
            if (_q2knots.empty() || q2 != _q2knots.back()) _q2knots.push_back(q2);
          }
        }
      }
      return _q2knots;
    }


  public:

    /// Check if x is in the grid range
    bool inRangeX(double x) const {
      assert(!xKnots().empty());
      if (x < xKnots().front()) return false;
      if (x > xKnots().back()) return false;
      return true;
    }

    /// Check if q2 is in the grid range
    bool inRangeQ2(double q2) const {
      assert(!q2Knots().empty());
      if (q2 < q2Knots().front()) return false;
      if (q2 > q2Knots().back()) return false;
      return true;
    }

    //@}


  private:

    /// Map of multi-flavour KnotArrays "binned" for lookup by low edge in Q2
    std::map<double, KnotArrayNF> _knotarrays;

    // /// Caching vector of x knot values
    // mutable std::vector<double> _xknots;

    /// Caching vector of Q2 knot values
    mutable std::vector<double> _q2knots;

    /// Typedef of smart pointer for ipol memory handling
    typedef unique_ptr<Interpolator> InterpolatorPtr;

    /// Typedef of smart pointer for xpol memory handling
    typedef unique_ptr<Extrapolator> ExtrapolatorPtr;

    /// Associated interpolator (mutable to allow laziness)
    mutable InterpolatorPtr _interpolator;

    /// Associated extrapolator (mutable to allow laziness)
    mutable ExtrapolatorPtr _extrapolator;

  };


}
#endif
