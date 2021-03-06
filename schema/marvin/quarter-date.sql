-- -*-sql-*-
--      $Id: quarter-date.sql 950 2001-10-21 07:39:27Z source $ 
--
--    Copyright 2000 X=X Computer Software Trust 
--                  Kangaroo Ground Australia 3097 
--
--
--   This is free software; you can redistribute it and/or modify 
--   it under the terms of the GNU General Public License published by 
--   the Free Software Foundation; either version 2, or (at your option) 
--   any later version. 
--
--   This software is distributed in the hope that it will be useful, 
--   but WITHOUT ANY WARRANTY; without even the implied warranty of 
--   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
--   GNU General Public License for more details. 
--
--   You should have received a copy of the GNU General Public License 
--   along with this software; see the file COPYING.  If not, write to 
--   the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
--
--   Report problems and direct all questions to: 
--
--       Rex McMaster, rmcm@compsoft.com.au 
--
-- General functions associated with any database
--


-- ------------------------------------------------------------
-- Convert timestamp to standard short date string
-- ------------------------------------------------------------

drop function quarter_date(timestamp);
create function quarter_date(timestamp)
returns text
as 'DECLARE
    -- NAME TABLE.ATTRIBUTE%TYPE;
    -- NAME TABLE%ROWTYPE;
    arg_ts alias for $1;

    BEGIN

        return extract(year from arg_ts::timestamp)||''-Q''||extract(quarter from arg_ts);
      
    END;'
  LANGUAGE 'plpgsql';
