/*!
 *	\file		Test_GeometryDynamicConfig.cpp
 *	\brief		Make the unit test for class GeometryDynamicConfig.
 *	
 */


#include "GeometryDynamic/GeometryDynamicConfig.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <gp_Quaternion.hxx>

TEST_CASE("Make the unit test for GeometryDynamic::GeometryDynamicConfig class", 
		  "[UTest_GeometryDynamicConfig]")
{
	// Instantiate the GeometryDynamicConfig
	GeometryDynamic::GeometryDynamicConfig& instance = GeometryDynamic::GeometryDynamicConfig::inst();

	SECTION("Check the method: getMaxDepth")
	{
		float max_depth = instance.getMaxDepth();
		REQUIRE_THAT(max_depth, Catch::Matchers::WithinRel(0.0f, 0.001f) || Catch::Matchers::WithinAbs(0.0f, 0.000001f));
	}

	SECTION("Check the method: setMaxDepth")
	{
		float max_depth = 5.0f;
		instance.setMaxDepth(max_depth);

		REQUIRE_THAT(instance.getMaxDepth(), Catch::Matchers::WithinRel(max_depth, 0.001f));
	}

	SECTION("Check the method: getMinDepth")
	{
		float min_depth = instance.getMinDepth();
		REQUIRE_THAT(min_depth, Catch::Matchers::WithinRel(0.1f, 0.0001f));
	}

	SECTION("Check the method: setMinDepth")
	{
		float min_depth = 3.05f;
		instance.setMinDepth(min_depth);

		REQUIRE_THAT(instance.getMinDepth(), Catch::Matchers::WithinAbs(min_depth, 0.000001f));
	}

	SECTION("Check the method: getHoleSegLength")
	{
		float hole_seg_length = instance.getHoleSegLength();
		REQUIRE_THAT(hole_seg_length, Catch::Matchers::WithinRel(5.0f, 0.0001f));
	}

	SECTION("Check the method: setHoleSegLength")
	{
		float hole_seg_length = 12.58f;
		instance.setHoleSegLength(hole_seg_length);

		REQUIRE_THAT(instance.getHoleSegLength(), Catch::Matchers::WithinRel(hole_seg_length, 0.0001f));
	}

	SECTION("Check the method: getMaxDiameter")
	{
		float max_diameter = instance.getMaxDiameter();
		REQUIRE_THAT(max_diameter, Catch::Matchers::WithinRel(0.0f, 0.000001f));
	}

	SECTION("Check the method: getMaxDiameter")
	{
		float max_diameter = 12.84f;
		instance.setMaxDiameter(max_diameter);

		REQUIRE_THAT(instance.getMaxDiameter(), Catch::Matchers::WithinRel(max_diameter, 0.000001f));
	}

	SECTION("Check the method: getMinDiameter")
	{
		float min_diameter = instance.getMinDiameter();
		REQUIRE_THAT(min_diameter, Catch::Matchers::WithinRel(0.0f, 0.000001f));
	}

	SECTION("Check the method: setMinDiameter")
	{
		float min_diameter = 5.04f;
		instance.setMinDiameter(min_diameter);

		REQUIRE_THAT(instance.getMinDiameter(), Catch::Matchers::WithinRelMatcher(min_diameter, 0.000001f));
	}

	SECTION("Check the method: getSprayDist")
	{
		float spray_dist = instance.getSprayDist();
		REQUIRE_THAT(spray_dist, Catch::Matchers::WithinRelMatcher(200.0f, 0.0001f));
	}

	SECTION("Check the method: setSprayDist")
	{
		float spray_dist = -10.2f;
		instance.setSprayDist(spray_dist);
		REQUIRE_THAT(instance.getSprayDist(), Catch::Matchers::WithinRelMatcher(200.0f, 0.0001f));

		spray_dist = 45.325f;
		instance.setSprayDist(spray_dist);
		REQUIRE_THAT(instance.getSprayDist(), Catch::Matchers::WithinRelMatcher(spray_dist, 0.0001f));
	}

	SECTION("Check the methods: setSprayWidth and getSprayWidth")
	{
		float spray_width = instance.getSprayWidth();
		REQUIRE_THAT(spray_width, Catch::Matchers::WithinRelMatcher(200.0f, 0.0001f));

		spray_width = -10.05f;
		instance.setSprayWidth(spray_width);
		REQUIRE_THAT(instance.getSprayWidth(), Catch::Matchers::WithinRelMatcher(200.0f, 0.0001f));

		spray_width = 10.05f;
		instance.setSprayWidth(spray_width);
		REQUIRE_THAT(instance.getSprayWidth(), Catch::Matchers::WithinRelMatcher(spray_width, 0.0001f));
	}

	SECTION("Check the methods: setSprayHeight and getSprayHeight")
	{
		float spray_height = instance.getSprayHeight();
		REQUIRE_THAT(spray_height, Catch::Matchers::WithinRelMatcher(100.0f, 0.0001f));

		spray_height = -5.82f;
		instance.setSprayHeight(spray_height);
		REQUIRE_THAT(instance.getSprayHeight(), Catch::Matchers::WithinRelMatcher(200.0f, 0.0001f));

		spray_height = 32.08f;
		instance.setSprayHeight(spray_height);
		REQUIRE_THAT(instance.getSprayHeight(), Catch::Matchers::WithinRelMatcher(spray_height, 0.0001f));
	}

	SECTION("Check the methods: getSprayPadding and setSprayPadding")
	{
		float spray_padding = instance.getSprayPadding();
		REQUIRE_THAT(spray_padding, Catch::Matchers::WithinRelMatcher(50.0f, 0.0001f));

		spray_padding = 46.78f;
		instance.setSprayPadding(spray_padding);
		REQUIRE_THAT(instance.getSprayPadding(), Catch::Matchers::WithinRelMatcher(spray_padding, 0.0001f));
	}

	SECTION("Check the methods: setModelTranslation, setModelRotation and getModelTransformation")
	{
		gp_Vec trans(gp_Pnt(2.0, 3.5, 5.8), gp_Pnt(10.2, -8.6, 4.95));
		instance.setModelTranslation(trans);

		gp_Vec rotation(-2.5, 1.0, 1.0);
		instance.setModelRotation(rotation);

		gp_Trsf transformation = instance.getModelTransformation();

		Standard_Real alpha{}, beta{}, gamma{};
		transformation.GetRotation().GetEulerAngles(gp_Extrinsic_XYZ, alpha, beta, gamma);
		REQUIRE_THAT(alpha, Catch::Matchers::WithinRelMatcher(rotation.X(), 0.0001));
		REQUIRE_THAT(beta, Catch::Matchers::WithinRelMatcher(rotation.Y(), 0.0001));
		REQUIRE_THAT(gamma, Catch::Matchers::WithinRelMatcher(rotation.Z(), 0.0001));

		auto& trans_part = transformation.TranslationPart();
		REQUIRE_THAT(trans_part.X(), Catch::Matchers::WithinRelMatcher(trans.X(), 0.0001));
		REQUIRE_THAT(trans_part.Y(), Catch::Matchers::WithinRelMatcher(trans.Y(), 0.0001));
		REQUIRE_THAT(trans_part.Z(), Catch::Matchers::WithinRelMatcher(trans.Z(), 0.0001));
	}

	SECTION("Check the methods: setSprayStartRef and getSprayStartRef")
	{
		gp_Pnt start_point(3.0, 4.0, 5.0);

		instance.setSprayStartRef(start_point);
		gp_Pnt point = instance.getSprayStartRef();

		REQUIRE_THAT(point.X(), Catch::Matchers::WithinRelMatcher(start_point.X(), 0.0001));
		REQUIRE_THAT(point.Y(), Catch::Matchers::WithinRelMatcher(start_point.Y(), 0.0001));
		REQUIRE_THAT(point.Z(), Catch::Matchers::WithinRelMatcher(start_point.Z(), 0.0001));
	}
}
