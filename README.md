# Geometry
A small convenience header-only library for linear algebra.  

## Dependencies, Installation, Usage  
**Dependencies:** None  
**Installation:** Download the header file *geometry.h*, include it, and you're ready to go.  
**Usage:** In namespace *geom::*, the library offers a struct for storing n-dimensional vectors in *R^n* or *Z^n* (i.e. with floating point- or integer coordinates) with several constructors, and overloads their operators.  
Furthermore, it offers a namespace *geom2d::* with some convenient functions for two-dimensional algebra like *cross product*, *perpendicular* and *normal*, *angle calculation*, and higher level stuff like *segment intersection*, *polygon area* and *convex hull* calcuation.


## Examples  
You can find the example code in this repository in *test/examples/*.  

**Ex1: Vector initialisation, operators, norm & dist**  
```cpp
#include "geometry/geometry.hpp"
#include <cassert>

typedef geom::Vec<double,3> Vec3d; //All our vectors have three double coordinates

int ex1() {
	Vec3d v1( 1.0, -1.0, -2.2 );
	Vec3d v2( 3.0, 1.0, -0.2 );

	Vec3d sub_v1v2 = v1 - v2;
	std::cout << "sub_v1v2: " << sub_v1v2.print() << std::endl; //sub_v1v2 == (-2.0, -2.0, -2.0 )
	
	Vec3d normalised = geom::normalize( sub_v1v2 );
	std::cout << "sub_v1v2 normalised: " << normalised.print() << std::endl; //normalised ==(-sqrt(1/3), -sqrt(1/3), -sqrt(1/3)
	
	assert( geom::in_range( geom::norm( normalised ), 1.0 ) ); //Double calculation isn't exact! Therefor, check result up to double precision
	
	std::cout << "Example1 successful executed!" << std::endl;

	return 0;
}
```


**Ex2: polygons & their area**  
```cpp
#include "geometry/geometry.hpp"

typedef geom::Vec<int,2> Vec2i; //All our vectors have two integer coordinates

int ex2(){
	Vec2i v1( 0, 0 );
	Vec2i v2( 2, 0 );
	Vec2i v3( 1, 1 );
	geom2d::polygon<int> p ( {v1,v2,v3} );

	double polygon_area = geom2d::area(p);
	std::cout << "Polygon area: " << polygon_area << std::endl; //polygon_area == 1
	assert( geom::in_range(polygon_area, 1.0) );

	return 0;
}
```


**Ex3: Point in polygon test & convex hull**  
```cpp
#include "geometry/geometry.hpp"

int ex3(){
	geom2d::polygon<double> p( { { 0.0,-0.1 },{ -0.1,0.0 },{ 0.0,0.1 },{ 0.1,0.0 } } );

	std::cout << "Point in polygon test: " << geom2d::point_in_polygon( { -0.04,0.02 }, p ) << std::endl; //Check if a point is in polygon
	assert( geom2d::point_in_polygon( { -0.04,0.02 }, p ) );

	std::vector<geom2d::Vec2D<int>> c ( { { 1,1 },{ -1,-3 },{ 0,1 },{ 10,10 },{ 2,-1 },{ -1,5 },{ -3,-5 },{ 3,-1 },{ 5,6 },{ 8,8 },{ 2,4 },{ 0,5 } } );
	auto conv_hull = geom2d::convex_hull( c );  //Compute the convex hull of a set of 2d-points, yielding a polygon conv_hull
	std::cout << geom::print( conv_hull ) << std::endl;
	assert( conv_hull.size() == 5 );
	
	return 0;
}
```


## Disclaimer  
The functionality of this library initially grew due to my personal need for it. Several projects, which I did not want to depend on a library as overkill as Boost, rely on this simple collection of linear algebra functions. The API might still change in the future. If you have any suggestions, find errors, miss some functions or want to give general feedback/criticism, I'd love to hear from you. Of course, [contributions](https://github.com/CrikeeIP/Geometry/pulls) are also very welcome.

## License  
Distributed under the *MIT Software License* (X11 license). (See accompanying file LICENSE.)
