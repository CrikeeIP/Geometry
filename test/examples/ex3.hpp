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