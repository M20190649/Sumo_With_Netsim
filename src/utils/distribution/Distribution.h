/****************************************************************************/
/// @file    Distribution.h
/// @author  Daniel Krajzewicz
/// @date    Sept 2002
/// @version $Id: Distribution.h 11671 2012-01-07 20:14:30Z behrisch $
///
// The base class for distribution descriptions.
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
// Copyright (C) 2001-2012 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef Distribution_h
#define Distribution_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <utils/common/Named.h>


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class Distribution
 * The base class for distribution descriptions. Only an interface
 *  specification.
 */
class Distribution : public Named {
public:
    /// Constructor
    Distribution(const std::string& id) : Named(id) { }

    /// Destructor
    virtual ~Distribution() { }

    /// Returns the maximum value of this distribution
    virtual SUMOReal getMax() const = 0;

};


#endif

/****************************************************************************/

