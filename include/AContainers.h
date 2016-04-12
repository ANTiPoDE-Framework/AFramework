/*******************************************************************************
 *	@author:	Milazzo Giuseppe
 *				UniversitÓ KORE Enna
 *	@e-mail:	milazzo.ga@gmail.com
 *				info@antipode-dev.org
 *******************************************************************************
 *	Software Licence:
 *******************************************************************************
 * 
 *	This file is part of AFramework.
 * 
 *	AFramework is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 * 
 *	AFramework is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with AFramework.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *	Copyright 2015, 2016 Milazzo Giuseppe 
 * 
*/

#ifndef ACONTAINERS_H
#define ACONTAINERS_H

#include "ACore.h"
#include "ACommons.h"

namespace AFramework{

	/*	Prototipi di classe (servono come forward-declaration					*/
	template <class T> class AAbstractList;
	template <class T> class ALinkedList;
	template <class T> class AList;
	
	template <class T> AAbstractList<T> & operator<<(AAbstractList<T> & list, const T & item);
	
	template <class T> class AAbstractList{
		
		public:

			enum Policy{
				AllowDuplicates,
				NotAllowDuplicates
			};
											AAbstractList	(const Policy			& policy = AllowDuplicates		);
											AAbstractList	(const AAbstractList<T> & list							);
			virtual			~				AAbstractList	(														);
			
			virtual	bool					insert			(const T				& item, const uint32_t & index	)		= 0;
			virtual bool					canInsert		(														) const = 0;
			virtual bool					remove			(const uint32_t			& index							)		= 0;
			virtual bool					clear			(														)		= 0;
			virtual T						at				(const uint32_t			& index							)		= 0;
			
					AList<uint32_t>			find			(const T				& item							) const;
					bool					init			(const Policy			& policy = AllowDuplicates		);
					bool					removeAll		(const T				& item							);
					bool					contains		(const T				& item							) const;
					bool					isEmpty			(														) const;
					bool					prepend			(const T				& item							);
					bool					append			(const T				& item							);
					bool					hasNext			(														) const;
					T						next			(														) const;
					uint32_t				size			(																	) const;
					
					bool					operator&&		(const T				& item							) const;
					bool					operator+=		(const T				& item							);
					bool					operator-=		(const T				& item							);
					bool					operator==		(const AAbstractList<T> & list							) const;
					bool					operator!=		(const AAbstractList<T> & list							) const;
					T						operator[]		(const uint32_t			& index							) const;
					AAbstractList<T>	&	operator=		(const AAbstractList<T> & list							);
		protected:
			mutable	uint32_t				m_index;
					uint32_t				m_size;
					Policy					m_policy;
					bool					m_flag;
	};
	
}

#endif	//	ACONTAINERS_H
