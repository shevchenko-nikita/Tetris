//#pragma once
//
//#include <vector>
//#include <cstdlib>
//
//enum class BlockColors
//{
//    NONE,
//    BLUE, // #0341AE
//    GREEN, // #72CB3B
//    YELLOW, // #FFD500
//    ORANGE, // #FF971C
//    RED // FF3213
//};
//
//namespace Shape
//{
//    enum class MoveDirection
//    {
//        NONE,
//        DOWN,
//        LEFT,
//        RIGHT
//    };
//
//    struct Coordinate
//    {
//        int x;
//        int y;
//    };
//
//    const std::vector<std::vector<Coordinate>> ALL_SHAPES =
//            {
//                    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
//                    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
//                    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
//                    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
//                    {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
//                    {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
//                    {{0, 0}, {0, 1}, {1, 1}, {1, 2}}
//            };
//
//    class Shape
//    {
//    public:
//        Shape()
//        {
//            Change();
//        }
//
//        bool Change()
//        {
//            int shape_id = rand() % 7;
//            blocks = ALL_SHAPES[shape_id];
//            color = static_cast<BlockColors>(rand() % 6);
//            return true;
//        }
//
//        bool CanMove(Shape::Shape& shape, MoveDirection direction);
//        bool Move(Shape::Shape& shape, MoveDirection direction);
//
//    private:
//
//        std::vector<Coordinate> blocks;
//        BlockColors color;
//    };
//};