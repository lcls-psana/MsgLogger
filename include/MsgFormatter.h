#ifndef MSGFORMATTER_HH
#define MSGFORMATTER_HH

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class MsgFormatter.
//
// Environment:
//      This software was developed for the BaBar collaboration.  If you
//      use all or part of it, please give an appropriate acknowledgement.
//
// Author List:
//      Andy Salnikov
//
// Copyright Information:
//      Copyright (C) 2005 SLAC
//
//------------------------------------------------------------------------

//-------------
// C Headers --
//-------------
extern "C" {
}

//---------------
// C++ Headers --
//---------------
#include <iostream>
#include <string>
#include <map>

//----------------------
// Base Class Headers --
//----------------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "MsgLogger/MsgLogLevel.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace MsgLogger {

class MsgLogRecord ;


/**
 *  @ingroup MsgLogger
 *
 *  The class which does message formating to show the message in  the
 *  human-readable format. In principle you can inherit this class and
 *  override some methods, but this implementation is already sufficiently
 *  generic and can be controlled completely via the format strings.
 *
 *  This software was developed for the BaBar collaboration.  If you
 *  use all or part of it, please give an appropriate acknowledgement.
 *
 *  Copyright (C) 2005 SLAC
 *
 *  @see MsgHandler
 *
 *  @version $Id$
 *
 *  @author Andy Salnikov
 */

class MsgFormatter {

public:

  // Constructor
  MsgFormatter( const std::string& fmt = "", const std::string& timefmt = "" ) ;

  // Destructor
  virtual ~MsgFormatter() ;

  // set format for all formatters
  static void addGlobalFormat ( const std::string& fmt ) ;
  static void addGlobalFormat ( MsgLogLevel level, const std::string& fmt ) ;

  // add level-specific format
  virtual void addFormat ( MsgLogLevel level, const std::string& fmt ) ;

  // format message to the output stream
  virtual void format ( const MsgLogRecord& rec, std::ostream& out ) ;

protected:

  // get a format string for a given level
  virtual const std::string& getFormat ( MsgLogLevel level ) const ;

private:

  // Data members
  std::string _timefmt ;
  std::string _fmtMap[MsgLogLevel::LAST_LEVEL+1] ;

  // Disable copy
  MsgFormatter( const MsgFormatter& );
  MsgFormatter& operator= ( const MsgFormatter& );

};
} // namespace MsgLogger

#endif // MSGFORMATTER_HH
