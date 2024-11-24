/*!
 *  \file       test_adapter_pattern.cc
 *  \brief      
 *  
 */


#include <catch2/catch_test_macros.hpp>

#include "adapter.hpp"
#include "text_shape.hpp"
#include "../common_utils/point.hpp"
#include "text_manipulator.hpp"

#include <memory>

TEST_CASE("Study and verify how adapter-pattern works", "[Adapter-Pattern]")
{
    SECTION("Demonstrate the client on how to apply the adapter-pattern")
    {
        Controller* target = new Adapter();
        target->pathPlanning();

        system("pause");
        delete target;
        
        CHECK(true);
    }

    SECTION("Check how to draw the text on the box")
    {
    #if (ADAPTER_TYPE == CLASS_ADAPTER)
        TextShape text_shape;
        Point box_bottom_left, box_top_right;
        text_shape.boundingBox(box_bottom_left, box_top_right);

        if (!text_shape.isEmpty())
        {
            Manipulator* manipulator = text_shape.createManipulator();
            // manipulate to draw the text on the bounding box
            if (manipulator != nullptr)
            {
                delete manipulator;
            }
        }
    #elif (ADAPTER_TYPE == OBJECT_ADAPTER)
        auto text_shape_ptr = std::make_shared<TextShape>(new TextView());
        Point box_bottom_left, box_top_right;
        text_shape_ptr->boundingBox(box_bottom_left, box_top_right);

        if (!text_shape_ptr->isEmpty())
        {
            Manipulator* manipulator = text_shape_ptr->createManipulator();
            // manipulate to draw the text on the bounding box
            if (manipulator != nullptr)
            {
                delete manipulator;
            }
        }
    #endif
        CHECK(true);
    }
}