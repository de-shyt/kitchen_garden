/*
   Copyright 2007 - 2008 MySQL AB, 2008 - 2009 Sun Microsystems, Inc.  All rights reserved.

   The MySQL Connector/C++ is licensed under the terms of the GPL
   <http://www.gnu.org/licenses/old-licenses/gpl-2.0.html>, like most
   MySQL Connectors. There are special exceptions to the terms and
   conditions of the GPL as it is applied to this software, see the
   FLOSS License Exception
   <http://www.mysql.com/about/legal/licensing/foss-exception.html>.
 */

#include "StatementTest.h"


namespace testsuite
{
namespace compliance
{

  // Same testsuite, as Statement test
class UnbufferedRsStmtTest : public StatementTest
{
private:
  typedef StatementTest super;

protected:

public:

  typedef UnbufferedRsStmtTest TestSuiteClass;
  UnbufferedRsStmtTest( const String & name );

  virtual void setUp();

};

REGISTER_FIXTURE(UnbufferedRsStmtTest);

}
}
