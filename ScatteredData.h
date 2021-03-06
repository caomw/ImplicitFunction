//-------------------------------------------------------------------
//
//  Permission is  hereby  granted, free  of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files  ( the "Software" ),  to  deal in  the  Software without
//  restriction, including  without limitation the rights to  use,
//  copy, modify,  merge, publish, distribute, sublicense,  and/or
//  sell copies of the Software, and to permit persons to whom the
//  Software is  furnished  to do  so,  subject  to  the following
//  conditions:
//
//  The above  copyright notice  and  this permission notice shall
//  be included  in  all copies  or  substantial  portions  of the
//  Software.
//
//  THE SOFTWARE IS  PROVIDED  "AS IS",  WITHOUT  WARRANTY  OF ANY
//  KIND,  EXPRESS OR IMPLIED, INCLUDING  BUT NOT  LIMITED  TO THE
//  WARRANTIES   OF  MERCHANTABILITY,  FITNESS  FOR  A  PARTICULAR
//  PURPOSE AND NONINFRINGEMENT. IN NO EVENT  SHALL THE AUTHORS OR
//  COPYRIGHT HOLDERS  BE  LIABLE FOR  ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
//  USE OR OTHER DEALINGS IN THE SOFTWARE.
//-------------------------------------------------------------------
//-------------------------------------------------------------------

#ifndef _SCATTEREDDATA_H_
#define _SCATTEREDDATA_H_

// STL Includes
#include <vector>
#include "vec3.h"

enum axis_t {X,Y,Z};

class ScatteredData
{
	public:
	ScatteredData();
	ScatteredData(std::vector<double> a, std::vector<double> b, std::vector<double> c, std::vector<double> d);
	void setData(std::vector<double> a, std::vector<double> b, std::vector<double> c, std::vector<double> d);
	std::vector<double> x[3], fnc;
	std::vector<vec3> myData;
	std::vector<axis_t> axisInformation;
        void computeOrdering();
	int origSize;
	vec3 centroid;
        //static int myAxis;

	private:
        void SDsort();
	void SDmultisort();
};

struct vec3Sorter {
  axis_t axisToSort;
  int myAxis;
  bool operator() (vec3 a,vec3 b) 
  { 
    if (axisToSort == X) myAxis = 0;
    if (axisToSort == Y) myAxis = 1;
    if (axisToSort == Z) myAxis = 2;
    return (a[myAxis]<b[myAxis]);
  }
};

#endif //_SCATTEREDDATA_H_
