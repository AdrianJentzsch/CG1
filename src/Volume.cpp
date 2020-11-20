// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute! 
// Copyright (C) CGV TU Dresden - All Rights Reserved

#include "Volume.h"

#include <iostream>

float ComputeVolume(const HEMesh& m)
{
	float vol = 0;
	int i;
	/*Task 1.2.2*/

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
		vol += points[0].dot(points[1].cross(points[2]));
	}

	return vol/ 6.0f;
}