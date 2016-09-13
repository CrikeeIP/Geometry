# Geometry
A small convenience header-only library for linear algebra.

##Dependencies, Installation, Usage
**Dependencies:** None  
**Installation:** Download the header files, include *geometry.h*, and you're ready to go.  
**Usage:** In namespace *geom::*, the library offers a struct for storing n-dimensional vectors in *R^n* or *Z^n* (i.e. with floating point- or integer coordinates) with several constructors, and overloads their operators.  
Furthermore, it offers a namespace *geom2d::* with some convenient functions for two-dimensional algebra like *cross product*, *perpendicular* and *normal*, *angle calculation*, and higher level stuff like *segment intersection* or *polygon area* calcuation.


##Examples

**Ex1**  
```cpp
#include "geometry/geometry.h"
#include <cassert>

typedef geom::Vec<double,3> Vec; //All our vectors have three double coordinates

int main() {
	Vec v1( 1.0, -1.0, -2.2 );
	Vec v2( 3.0, 1.0, -0.2 );

	Vec sub_v1v2 = v1 - v2;
	std::cout << "sub_v1v2: " << sub_v1v2.print() << std::endl; //sub_v1v2 == (-2.0, -2.0, -2.0 )
	
	Vec normalised = geom::normalize( sub_v1v2 );
	std::cout << "sub_v1v2 normalised: " << sub_v1v2.print() << std::endl; //normalised ==(-sqrt(1/3), -sqrt(1/3), -sqrt(1/3)
	
	assert( geom::in_range( geom::norm( normalised ), 1.0 ) ); //Double calculation isn't exact! Therefor, check result up to double precision
	
	std::cout << "Example1 successful executed!" << std::endl;
}
```


**Ex2**  
```cpp
#include "geometry/geometry.h"

typedef geom::Vec<int,2> Vec; //All our vectors have two integer coordinates

int main(){
  Vec v1( 0, 0 );
  Vec v2( 2, 0 );
  Vec v3( 1, 1 );
  geom2d::polygon<int> p ( {v1,v2,v3} );

  double polygon_area = geom2d::area(p);
  std::cout << "Polygon area: " << polygon_area << std::endl; //polygon_area == 1
}
```



**Ex3**  
```cpp
#include "geometry/geometry.h"



int main(){

  geom2d::polygon<double> p ( {{0, -1}, {-1, 0}, {0,1}, {1,0}} );



  std::cout << "Point in polygon test: " << geom2d::point_in_polygon({-0.4,0.2}, p) << std::endl; //Check if a point is in polygon



  geom2d::point_cloud<int> c ({ {1,1}, {0,1}, {10,10}, {-1,5}, {-3, -5}, {3, -1}, {5,6} }); //Compute the convex hull of a set of 2d-points

  geom2d::polygon<int> conv_hull = geom2d::convex_hull(c);

  for( const auto& x : conv_hull ){

	std::cout << x.print() << " ; ";

  }

}
```


##Disclaimer
The functionality of this library initially grew due to my personal need for it. Several projects, which I did not want to depend on a library as overkill as Boost, rely on this simple collection of linear algebra functions. The API might still change in the future. If you have any suggestions, find errors, miss some functions or want to give general feedback/criticism, I'd love to hear from you. Of course, [contributions](https://github.com/CrikeeIP/Geometry/pulls) are also very welcome.

##License
Distributed under the *MIT Software License* (X11 license). (See accompanying file LICENSE.)
