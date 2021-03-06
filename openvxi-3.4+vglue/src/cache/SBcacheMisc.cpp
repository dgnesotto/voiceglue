
/****************License************************************************
 * Vocalocity OpenVXI
 * Copyright (C) 2004-2005 by Vocalocity, Inc. All Rights Reserved.
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * Vocalocity, the Vocalocity logo, and VocalOS are trademarks or 
 * registered trademarks of Vocalocity, Inc. 
 * OpenVXI is a trademark of Scansoft, Inc. and used under license 
 * by Vocalocity.
 ***********************************************************************/

// -----1=0-------2=0-------3=0-------4=0-------5=0-------6=0-------7=0-------8

#include "SBcacheMisc.hpp"   // For these classes

// Define static class members
const char SBcachePath::PATH_SEPARATOR = '/';

// -----1=0-------2=0-------3=0-------4=0-------5=0-------6=0-------7=0-------8


// Create the directory tree for the path
VXIcacheResult SBcachePath::CreateDirectories( ) const
{
  VXIcacheResult rc = VXIcache_RESULT_SUCCESS;

  // Go through the directories for the relative portion and create
  // them
  SBcacheNString::size_type componentLen = _baseLen;
  while ( componentLen != SBcacheNString::npos ) {
    SBcacheNString tempPath (_path, 0, componentLen);
    SBcacheMkdir (tempPath);
    componentLen = _path.find_first_of ("/\\", componentLen + 1);
  }

  return rc;
}
