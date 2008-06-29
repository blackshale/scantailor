/*
    Scan Tailor - Interactive post-processing tool for scanned pages.
    Copyright (C) 2007-2008  Joseph Artsimovich <joseph_a@mail.ru>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FILTERUIINTERFACE_H_
#define FILTERUIINTERFACE_H_

#include "PageId.h"

class DebugImages;
class FilterOptionsWidget;
class QWidget;

/**
 * \brief A reduced interface to MainWindow to allow filters to manupulate the UI.
 */
class FilterUiInterface
{
public:
	enum Ownership { KEEP_OWNERSHIP, TRANSFER_OWNERSHIP };
	
	virtual ~FilterUiInterface() {}
	
	virtual void setOptionsWidget(
		FilterOptionsWidget* widget, Ownership ownership) = 0;
	
	virtual void setImageWidget(
		QWidget* widget, Ownership ownership,
		DebugImages const* debug_images = 0) = 0;
	
	virtual void invalidateThumbnail(PageId const& page_id) = 0;
};

#endif
