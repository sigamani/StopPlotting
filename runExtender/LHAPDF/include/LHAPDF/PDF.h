// -*- C++ -*-
//
// This file is part of LHAPDF
// Copyright (C) 2012-2014 The LHAPDF collaboration (see AUTHORS for details)
//
#pragma once
#ifndef LHAPDF_PDF_H
#define LHAPDF_PDF_H

#include "LHAPDF/PDFInfo.h"
#include "LHAPDF/PDFIndex.h"
#include "LHAPDF/Factories.h"
#include "LHAPDF/AlphaS.h"
#include "LHAPDF/Utils.h"
#include "LHAPDF/Paths.h"
#include "LHAPDF/Exceptions.h"
#include "LHAPDF/Version.h"
#include "LHAPDF/Config.h"

namespace LHAPDF {


  /// @brief PDF is the general interface for access to parton density information.
  ///
  /// The PDF interface declares the general form of all PDF types, such as Grid based or analytic.
  class PDF {
  protected: //< These constructors should only be called by subclasses

    /// Internal convenience typedef for the AlphaS object handle
    // typedef AlphaS* AlphaSPtr;
    typedef auto_ptr<AlphaS> AlphaSPtr;

    /// Force initialization of the only non-class member.
    PDF() : _forcePos(0) { }


  public:

    /// Virtual destructor, to allow unfettered inheritance
    virtual ~PDF() { }

    //@}


  protected:


    /// @name Helper methods for info loading / path setting, used by derived types
    //@{

    void _loadInfo(const std::string& mempath) {
      if (mempath.empty())
        throw UserError("Tried to initialize a PDF with a null data file path... oops");
      _mempath = mempath;
      _info = PDFInfo(mempath);
      //_info = PDFInfo(_setname(), memberID());
      /// Check that this is a sufficient version LHAPDF for this PDF
      if (_info.has_key("MinLHAPDFVersion")) {
        if (_info.get_entry_as<int>("MinLHAPDFVersion") > LHAPDF_VERSION_CODE) {
          throw VersionError("Current LHAPDF version " + to_str(LHAPDF_VERSION_CODE)
                             + " less than required " + _info.get_entry("MinLHAPDFVersion"));
        }
      }
      /// Print out a banner if sufficient verbosity is enabled
      const int v = verbosity();
      if (v > 0) {
        std::cout << "LHAPDF " << version() << " loading " << mempath << std::endl;
        print(std::cout, v);
      }
      /// Print out a warning message if this PDF data is unvalidated
      if (_info.get_entry_as<int>("DataVersion", -1) < 0) {
        std::cerr << "WARNING: PDF #" << lhapdfID() << " is preliminary, unvalidated, "
                  << "and not for production use!" << std::endl;
      }
    }

    void _loadInfo(const std::string& setname, int member) {
      const string searchpath = findpdfmempath(setname, member);
      if (searchpath.empty())
        throw UserError("Can't find a valid PDF " + setname + "/" + to_str(member));
      _loadInfo(searchpath);
    }

    void _loadInfo(int lhaid) {
      const pair<string,int> setname_memid = lookupPDF(lhaid);
      if (setname_memid.second == -1)
        throw IndexError("Can't find a PDF with LHAPDF ID = " + to_str(lhaid));
      _loadInfo(setname_memid.first, setname_memid.second);
    }

    //@}


  public:

    /// @name PDF values
    //@{

    /// @brief Get the PDF xf(x) value at (x,q2) for the given PID.
    ///
    /// All grids are defined in Q2 rather than Q since the natural value
    /// in MC programs is squared, so we typically avoid an expensive sqrt() call.
    ///
    /// @param id PDG parton ID
    /// @param x Momentum fraction
    /// @param q2 Squared energy (renormalization) scale
    /// @return The value of xf(x,q2)
    double xfxQ2(int id, double x, double q2) const {
      // Physical x range check
      if (!inPhysicalRangeX(x)) {
        throw RangeError("Unphysical x given: " + to_str(x));
      }
      // Physical Q2 range check
      if (!inPhysicalRangeQ2(q2)) {
        throw RangeError("Unphysical Q2 given: " + to_str(q2));
      }
      // Treat PID = 0 as always equivalent to a gluon: query as PID = 21
      const int id2 = (id != 0) ? id : 21;
      // Undefined PIDs
      if (!hasFlavor(id2)) {
        /// @todo Should look up the UndefFlavorAction flag, but efficiency hit for top?
        //throw FlavorError("Undefined flavour requested: " + to_str(id));
        return 0.0;
      }
      // Call the delegated method in the concrete PDF object to calculate the in-range value
      double xfx = _xfxQ2(id2, x, q2);
      // Apply positivity forcing at the enabled level
      switch (forcePositive()) {
      case 0: break;
      case 1: if (xfx < 0) xfx = 0; break;
      case 2: if (xfx < 1e-10) xfx = 1e-10; break;
      default: throw LogicError("ForcePositive value not in expected range!");
      }
      // Return
      return xfx;
    }


    /// @brief Get the PDF xf(x) value at (x,q) for the given PID.
    ///
    /// xfxQ will square the given q and return the value from xfxQ2.
    /// All grids are defined in q2 rather than q since the natural value
    /// in MC programs is squared, so we typically avoid an expensive sqrt() call.
    ///
    /// @param id PDG parton ID
    /// @param x Momentum fraction
    /// @param q Energy (renormalization) scale
    /// @return The value of xf(x,q2)
    double xfxQ(int id, double x, double q) const {
      return xfxQ2(id, x, q*q);
    }


    /// @brief Get the PDF xf(x) value at (x,q2) for all supported PIDs.
    ///
    /// This version fills a user-supplied map to avoid container construction
    /// costs on every call.
    ///
    /// @param x Momentum fraction
    /// @param q2 Squared energy (renormalization) scale
    /// @param rtn Map of PDF xf(x,q2) values, to be filled
    void xfxQ2(double x, double q2, std::map<int, double>& rtn) const {
      rtn.clear();
      BOOST_FOREACH (int id, flavors()) rtn[id] = xfxQ2(id, x, q2);
    }


    /// @brief Get the PDF xf(x) value at (x,q) for all supported PIDs.
    ///
    /// This version fills a user-supplied map to avoid container construction
    /// costs on every call.
    ///
    /// @param x Momentum fraction
    /// @param q Energy (renormalization) scale
    /// @param rtn Map of PDF xf(x,q) values, to be filled
    void xfxQ(double x, double q, std::map<int, double>& rtn) const {
      xfxQ2(x, q*q, rtn);
    }


    /// @brief Get the PDF xf(x) value at (x,q2) for "standard" PIDs.
    ///
    /// This version fills a user-supplied vector to avoid container
    /// construction costs on every call.
    ///
    /// The filled vector follows the LHAPDF5 convention, with 13 entries
    /// running in the PDF ID order [-6, -5, ..., -1, 21, 1, ... 5, 6], i.e.
    /// quark PDF values will be at vector index pid+6 and the gluon at index 6.
    ///
    /// @param x Momentum fraction
    /// @param q2 Squared energy (renormalization) scale
    /// @param rtn Vector of PDF xf(x,q2) values, to be filled
    void xfxQ2(double x, double q2, std::vector<double>& rtn) const {
      rtn.clear();
      rtn.resize(13);
      for (int i = 0; i < 13; ++i) {
        const int id = i-6; // PID = 0 is automatically treated as PID = 21
        rtn[i] = xfxQ2(id, x, q2);
      }
    }


    /// @brief Get the PDF xf(x) value at (x,q) for "standard" PIDs.
    ///
    /// This version fills a user-supplied vector to avoid container
    /// construction costs on every call.
    ///
    /// The filled vector follows the LHAPDF5 convention, with 13 entries
    /// running in the PDF ID order [-6, -5, ..., -1, 21, 1, ... 5, 6], i.e.
    /// quark PDF values will be at vector index pid+6 and the gluon at index 6.
    ///
    /// @param x Momentum fraction
    /// @param q Energy (renormalization) scale
    /// @param rtn Vector of PDF xf(x,q) values, to be filled
    void xfxQ(double x, double q, std::vector<double>& rtn) const {
      xfxQ2(x, q*q, rtn);
    }


    /// @brief Get the PDF xf(x) value at (x,q2) for all supported PIDs.
    ///
    /// This version creates a new map on every call: prefer to use the
    /// fill-in-place version with a user-supplied map for many calls.
    ///
    /// @param x Momentum fraction
    /// @param q2 Squared energy (renormalization) scale
    /// @return A map of PDF xf(x,q2) values
    std::map<int, double> xfxQ2(double x, double q2) const {
      std::map<int, double> rtn;
      xfxQ2(x, q2, rtn);
      return rtn;
    }

    /// @brief Get the PDF xf(x) value at (x,q) for all supported PIDs.
    ///
    /// This version creates a new map on every call: prefer to use the
    /// fill-in-place version with a user-supplied map for many calls.
    ///
    /// xfxQ will square the given q and return the value from xfxQ2.
    /// All grids are defined in q2 rather than q since the natural value
    /// in MC programs is squared, so we typically avoid an expensive sqrt() call.
    ///
    /// @param x Momentum fraction
    /// @param q Energy (renormalization) scale
    /// @return A map of PDF xf(x,q) values
    std::map<int, double> xfxQ(double x, double q) const {
      return xfxQ2(x, q*q);
    }


  protected:

    /// @brief Calculate the PDF xf(x) value at (x,q2) for the given PID.
    ///
    /// This is the key function to be overridden in concrete PDF types, since
    /// it actually does the calculation of xf(x,Q2) by analytic, interpolation,
    /// or other means. The user-called xfxQ2 method exists so that the physical
    /// range and PID checks need only be done in one place, rather than need to
    /// be re-implemented in each concrete implementation.
    ///
    /// @param id Parton ID in the PDG scheme
    /// @param x Momentum fraction
    /// @param q2 Squared energy (renormalization) scale
    /// @return the value of xf(x,q2)
    virtual double _xfxQ2(int id, double x, double q2) const = 0;

    //@}


  public:

    /// @name Ranges of validity
    //@{

    /// Minimum valid x value for this PDF.
    virtual double xMin() {
      if (info().has_key("XMin"))
        return info().get_entry_as<double>("XMin");
      return numeric_limits<double>::epsilon();
    }

    /// Maximum valid x value for this PDF.
    virtual double xMax() {
      if (info().has_key("XMax"))
        return info().get_entry_as<double>("XMax");
      return 1.0;
    }

    /// Minimum valid Q value for this PDF (in GeV).
    /// @note This function calls sqrt(q2Min()). For better CPU efficiency and accuracy use q2Min() directly.
    virtual double qMin() {
      return info().get_entry_as<double>("QMin", 0);
    }

    /// @brief Maximum valid Q value for this PDF (in GeV).
    /// @note This function calls sqrt(q2Max()). For better CPU efficiency and accuracy use q2Max() directly.
    virtual double qMax() {
      return info().get_entry_as<double>("QMax", numeric_limits<double>::max());
    }

    /// Minimum valid Q2 value for this PDF (in GeV2).
    virtual double q2Min() {
      return sqr(this->qMin());
    }

    /// Maximum valid Q2 value for this PDF (in GeV2).
    virtual double q2Max() {
      // Explicitly re-access this from the info, to avoid an overflow from squaring double_max
      return (info().has_key("QMax")) ? sqr(info().get_entry_as<double>("QMax")) : numeric_limits<double>::max();
    }

    /// @brief Check whether PDF is set to only return positive (definite) values or not.
    ///
    /// This is to avoid overshooting in to negative values when
    /// interpolating/extrapolating PDFs that sharply decrease towards zero.
    /// 0 = unforced, 1 = forced positive, 2 = forced positive definite (>= 1e-10)
    int forcePositive() const {
      if (_forcePos < 0) //< Caching
        _forcePos = info().get_entry_as<unsigned int>("ForcePositive", 0);
      return _forcePos;
    }

    /// @brief Check whether the given x is physically valid
    ///
    /// Returns false for x less than 0 or greater than 1, since it
    /// is a momentum fraction and not valid outside those values.
    bool inPhysicalRangeX(double x) const {
      return x >= 0.0 && x <= 1.0;
    }

    /// @brief Check whether the given Q2 is physically valid
    ///
    /// Returns false for Q2 less than 0 (Q must be real-valued).
    bool inPhysicalRangeQ2(double q2) const {
      return q2 >= 0.0;
    }

    /// @brief Check whether the given Q is physically valid
    ///
    /// Returns false for Q less than 0 (Q must be positive).
    bool inPhysicalRangeQ(double q) const {
      return inPhysicalRangeQ2(q*q);
    }

    /// Check whether the given (x,Q2) is physically valid
    bool inPhysicalRangeXQ2(double x, double q2) const {
      return inPhysicalRangeX(x) && inPhysicalRangeQ2(q2);
    }

    /// Check whether the given (x,Q) is physically valid
    bool inPhysicalRangeXQ(double x, double q) const {
      return inPhysicalRangeX(x) && inPhysicalRangeQ(q);
    }

    /// @brief Grid range check for Q
    ///
    /// Return true when given Q is in the coverage range of this PDF.
    /// It actually squares the given Q and returns value from inRangeQ2.
    ///
    /// @param q Energy scale
    /// @return Whether q is in range
    virtual bool inRangeQ(double q) const {
      return inRangeQ2(q*q);
    }

    /// @brief Grid range check for Q2
    ///
    /// Return true when given Q2 is in the coverage range of this PDF.
    ///
    /// @param q2 Squared energy scale
    /// @return Whether q2 is in range
    virtual bool inRangeQ2(double q2) const = 0;

    /// @brief Grid range check for x
    ///
    /// Return true when given x is in the coverage range of this PDF.
    ///
    /// @param x Momentum fraction
    /// @return Whether x is in range
    virtual bool inRangeX(double x) const = 0;

    /// Combined range check for x and Q
    virtual bool inRangeXQ(double x, double q) const {
      return inRangeX(x) && inRangeQ(q);
    }

    /// Combined range check for x and Q2
    bool inRangeXQ2(double x, double q2) const {
      return inRangeX(x) && inRangeQ2(q2);
    }

    //@}


    /// @name Generic member-level metadata (including cascaded metadata from set & config level)
    //@{

    /// Get the info class that actually stores and handles the metadata
    PDFInfo& info() { return _info; }

    /// Get the info class that actually stores and handles the metadata (const version)
    const PDFInfo& info() const { return _info; }

    /// @brief Get the PDF set of which this is a member
    ///
    /// Obtained from the member file path, not Info-based metadata.
    PDFSet& set() const {
      return getPDFSet(_setname());
    }

    //@}


    /// @name Member-level metadata
    //@{

    /// @brief PDF member local ID number
    ///
    /// Obtained from the member file path, not Info-based metadata.
    int memberID() const {
      const string memname = file_stem(_mempath);
      assert(memname.length() > 5); // There must be more to the filename stem than just the _nnnn suffix
      const int memid = lexical_cast<int>(memname.substr(memname.length()-4)); //< Last 4 chars should be the member number
      return memid;
    }

    /// @brief PDF member global LHAPDF ID number
    ///
    /// Obtained from the member ID and the set's LHAPDF ID index
    int lhapdfID() const {
      /// @todo Use set().lhapdfID() + memberID()
      return lookupLHAPDFID(_setname(), memberID());
    }

    /// Description of this PDF member
    std::string description() const {
      return info().get_entry("PdfDesc", "");
    }

    /// Version of this PDF's data file
    int dataversion() const {
      return info().get_entry_as<int>("DataVersion", -1);
    }

    /// Get the type of PDF member that this object represents (central, error)
    std::string type() const {
      return to_lower_copy(info().get_entry("PdfType"));
    }

    //@}


    /// Summary printout
    void print(std::ostream& os=std::cout, int verbosity=1) const;


    /// @name Parton content and QCD parameters
    //@{

    /// @brief List of flavours defined by this PDF set.
    ///
    /// This list is stored locally after its initial read from the Info object
    /// to avoid unnecessary lookups and string decoding, since e.g. it is
    /// looked at by every call to the GridPDF's Interpolator and Extrapolator
    /// classes.
    ///
    /// @todo Make virtual for AnalyticPDF? Or allow manual setting of the Info?
    const std::vector<int>& flavors() const {
      if (_flavors.empty()) {
        _flavors = info().get_entry_as< vector<int> >("Flavors");
        sort(_flavors.begin(), _flavors.end());
      }
      return _flavors;
    }

    /// Checks whether @a id is a valid parton for this PDF.
    bool hasFlavor(int id) const {
      const vector<int>& ids = flavors();
      return find(ids.begin(), ids.end(), id) != ids.end();
    }

    /// @brief Order of QCD at which this PDF has been constructed
    ///
    /// "Order" is defined here and throughout LHAPDF as the maximum number of
    /// loops included in the matrix elements, in order to have an integer value
    /// for easy use in comparisons, as opposed to "LO", "NLO", etc. strings.
    int orderQCD() const {
      return info().get_entry_as<int>("OrderQCD");
    }
    /// @deprecated Use orderQCD instead
    int qcdOrder() const {
      return orderQCD(); }

    //@}


    /// @name QCD running coupling calculation
    //@{

    /// @brief Set the AlphaS calculator by pointer
    ///
    /// The provided AlphaS must have been new'd, as it will not be copied
    /// and ownership passes to this GridPDF: delete will be called on this ptr
    /// when this PDF goes out of scope or another setAlphaS call is made.
    void setAlphaS(AlphaS* alphas) {
      _alphas.reset(alphas);
    }

    /// @brief Check if an AlphaS calculator is set
    bool hasAlphaS() const {
      return _alphas.get() != 0;
    }

    /// @brief Retrieve the AlphaS object for this PDF
    AlphaS& alphaS() {
      return *_alphas;
    }

    /// @brief Retrieve the AlphaS object for this PDF (const)
    const AlphaS& alphaS() const {
      return *_alphas;
    }

    /// @brief Value of alpha_s(Q2) used by this PDF
    ///
    /// Calculated numerically, analytically, or interpolated according to
    /// metadata, using the AlphaS classes.
    double alphasQ(double q) const {
      return alphasQ2(q*q);
    }

    /// @brief Value of alpha_s(Q2) used by this PDF
    ///
    /// Calculated numerically, analytically, or interpolated according to
    /// metadata, using the AlphaS classes.
    double alphasQ2(double q2) const {
      if (!hasAlphaS())
        _alphas.reset( mkAlphaS(info()) );
      return _alphas->alphasQ2(q2);
    }

    //@}


  protected:

    /// Get the set name from the member data file path (for internal use only)
    std::string _setname() const {
      return basename(dirname(_mempath));
    }

    /// Member data file path
    std::string _mempath;

    /// Metadata container
    PDFInfo _info;

    /// Locally cached list of supported PIDs
    mutable vector<int> _flavors;

    /// Optionally loaded AlphaS object
    mutable AlphaSPtr _alphas;

    /// @brief Cached flag for whether to return only positive (or postive definite) PDF values
    ///
    /// A negative value indicates that the flag has not been set. 0 = no
    /// forcing, 1 = force positive (i.e. 0 is permitted, negative values are
    /// not), 2 = force positive definite (i.e. no values less than 1e-10).
    mutable int _forcePos;

  };


}
#endif
