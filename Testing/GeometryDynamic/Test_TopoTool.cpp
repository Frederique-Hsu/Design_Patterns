/*!
 *	\file		Test_TopoTool.cpp
 *	\brief		Make the unit test for TopoTool class
 *	
 */


#include "GeometryDynamic/TopoTool.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <AIS_TextLabel.hxx>

TEST_CASE("Make the unit test for GeometryDynamic::TopoTool class from GeometryDynamic library",
		  "[UTest_TopoTool]")
{
	using namespace GeometryDynamic;

	SECTION("Check the static method: xyzToVec")
	{
		gp_XYZ coordinate(3.0, 4.0, 5.0);

		Eigen::Vector3d vector = TopoTool::xyzToVec(coordinate);
		auto vec_x = vector.x();
		auto x = coordinate.X();

		REQUIRE_THAT(vec_x, Catch::Matchers::WithinRelMatcher(x, 0.0001));
		REQUIRE_THAT(vector.y(), Catch::Matchers::WithinRelMatcher(coordinate.Y(), 0.0001));
		REQUIRE_THAT(vector.z(), Catch::Matchers::WithinRelMatcher(coordinate.Z(), 0.0001));
	}

#if false
	SECTION("Check the static method: removeMargin")
	{
		SKIP();

		gp_Dir direction(0.000000099,		// < 1.e-7
						 0.999999998,		// 1.0 - 0.999999998 = 0.000000002 < 1.e-7
						 1.000000098);		// 1.000000098 - 1.0 = 0.000000002 < 1.e-7

		TopoTool::removeMargin(direction);
		double x = direction.X();
		double y = direction.Y();
		double z = direction.Z();

		std::cout << "x = " << std::setprecision(15) << x << std::endl;
		std::cout << "y = " << std::setprecision(15) << y << std::endl;
		std::cout << "z = " << std::setprecision(15) << z << std::endl;

		CHECK_THAT(x, Catch::Matchers::WithinRelMatcher(0.0, 1.e-8));
		CHECK_THAT(y, Catch::Matchers::WithinRelMatcher(1.0, 1.e-7));
		CHECK_THAT(z, Catch::Matchers::WithinRelMatcher(1.0, 1.e-7));	// Precision failed.
	}
#endif

	SECTION("Check the static method: createTextMarker")
	{
		gp_Pnt origin(0.0, 0.0, 0.0);
		char* raw_text = "origin";

		Handle(AIS_TextLabel) origin_label = TopoTool::createTextMarker(raw_text, origin);
		AIS_TextLabel* label_text_ptr = origin_label.get();

		auto text = label_text_ptr->Text();
		text.Print(std::cout);
		auto length = text.Length();
		CHECK(length == std::strlen(raw_text));

		auto str = text.ToExtString();
		Standard_ExtString ustr(u"origin");

		for (auto index = 0U; index < length; ++index)
		{
			CHECK(*(str + index) == *(ustr + index));
		}
	}
}