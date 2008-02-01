/*
    Warzone 2100 Lobbyserver, serves as a meeting place to set up games
    Copyright (C) 2007  Giel van Schijndel

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    $Revision$
    $Id$
    $HeadURL$
*/

#ifndef __INCLUDED_LIB_SOUND_GENERAL_RAII_COUNTER_HPP__
#define __INCLUDED_LIB_SOUND_GENERAL_RAII_COUNTER_HPP__

// An exception safe (not thread safe though) counter
class RAIICounter
{
    public:
        RAIICounter();

        inline operator unsigned int() const
        {
            return _count;
        }

        class scope_counted
        {
            public:
                scope_counted(RAIICounter& counter);
                scope_counted(const scope_counted& org);
                ~scope_counted();

            private:
                // Private assignment operator since I'm too lazy to write one
                const scope_counted& operator=(const scope_counted&);

            private:
                RAIICounter& _counter;
        };

    private:
        // Private and unimplemented copy constructor and copy assignment operator since we don't have sensible copy semantics
        RAIICounter(const RAIICounter&);
        RAIICounter& operator=(const RAIICounter&);

    private:
        unsigned int _count;
};

#endif // __INCLUDED_LIB_SOUND_GENERAL_RAII_COUNTER_HPP__
