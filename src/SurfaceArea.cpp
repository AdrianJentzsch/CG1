// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute! 
// Copyright (C) CGV TU Dresden - All Rights Reserved

#include "SurfaceArea.h"

#include <iostream>

float ComputeSurfaceArea(const HEMesh& m)
{
	float area = 0;
	/* Task 1.2.2 */
	
	int i;
	
	/* todo
	if (m.is_trimesh()) {
		std::vector<OpenMesh::Vec3f> points(3);
		for (auto f : m.faces())
		{
			OpenMesh::Vec3f n;
			std::cout << "Face: " << f << std::endl;
			i = 0;
			for (auto v : m.fv_range(f)) {
				points[i] = m.point(v);
				i++;
				std::cout << "vertex " << m.point(v) << std::endl;
			}
			OpenMesh::Vec3f crosss = points[0].cross(points[1]) + points[1].cross(points[2]) + points[2].cross(points[0]);
			area += crosss.norm() / 2.0f;
			std::cout << "area: " << area << std::endl;
		}
	}
	else {
		*/
		std::cout << "No tri mesh." << std::endl;

		for (auto f : m.faces())
		{
			OpenMesh::Vec3f n;
			std::cout << "Face: " << f << std::endl;
			std::vector<OpenMesh::Vec3f> points;
			i = 0;
			for (auto v : m.fv_range(f)) {
				points.push_back(m.point(v));
				i++;
				std::cout << "vertex " << m.point(v) << std::endl;
			}
			std::cout << "No of points " << points.size() << std::endl;
			OpenMesh::Vec3f crosss(0,0,0);
			for (int i = 0; i < points.size()-1; i++) {
				std::cout << i << std::endl;
				crosss += points[i].cross(points[i+1]); 
			}
			crosss += points[points.size()-1].cross(points[0]);
			area += crosss.norm() / 2.0f;
			std::cout << "area: " << area << std::endl;
		}


	// }

	return area;
}