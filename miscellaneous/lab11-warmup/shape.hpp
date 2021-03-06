/*
 * shape.hpp
 * CS202
 * April 10, 2020
 * Bryan Beus
 * Header file for the Shape base class
 */

#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::string;

class Shape {
    public:
        Shape(const string& name);
        ~Shape();

        virtual void draw();

    private:
        int x;
        int y;

        string name_;
};

Shape::Shape(const string& name) 
    : x(0), y(0), name_(name) { 
        cout << "Shape::Shape() ----> " << name_ << endl;
}

Shape::~Shape() {
    cout << "Shape::~Shape() ----> " << name_ << endl;
}

void Shape::draw() {
    cout << "Shape::draw() ----> " << name_ << endl;
}

class Box : public Shape {
    public:
        Box();
        ~Box();

        void draw() override;

    private:
        int width_ { 1 };
        int height_ { 1 }; 
};

Box::Box() :
    Shape("Box")
{
    cout << "Box::Box()" << endl;
}

Box::~Box() {
    cout << "Box::~Box()" << endl;
}

void Box::draw() {
    Shape::draw();
    cout << "box " << width_ << " x " << height_ << endl;
}

class Circle : public Shape {
    public: 
        Circle();
        ~Circle();

        void draw() override;
    private: 
        int radius_{ 1 };
};

Circle::Circle() : Shape("Circle") {
    cout << "Circle::Circle()" << endl;
}

Circle::~Circle() {
    cout << "Circle::~Circle()" << endl;
}

void Circle::draw() {
    Shape::draw();

    cout << "circle radius " << radius_ << endl;
}

class AggregateShape {
    public:
        AggregateShape();
        ~AggregateShape();

        void draw();
    private:
        Box box;
        Circle circle;
};

AggregateShape::AggregateShape() {
    cout << "AggregateShape::AggregateShape()" << endl;
}

AggregateShape::~AggregateShape() {
    cout << "AggregateShape::~AggregateShape()" << endl;
}

void AggregateShape::draw() {
    box.draw();
    circle.draw(); 
}

void TestShapes() {
    cout << "---------------" << endl;
    Shape base{ "Shape" };
    Box box;
    Circle circle;
    AggregateShape ashape;
    cout << "drawing shape" << endl;
    base.draw();
    cout << "drawing box" << endl;
    box.draw();
    cout << "drawing circle" << endl;
    circle.draw();
    cout << "drawing aggregateshape" << endl;
    ashape.draw();
    cout << "---------------" << endl;

}

enum class ShapeType {
    Box,
    Circle
};

class ShapeFactory {
    public:
        static std::shared_ptr<Shape> Create(ShapeType shape) {
            switch (shape) {
                case ShapeType::Circle:
                    return std::make_shared<Circle>();
                case ShapeType::Box:
                    return std::make_shared<Box>();
                default:
                    throw std::runtime_error("Invalid");
                    break;
            }
        }
};

void TestFactory() {
    std::vector<std::shared_ptr<Shape>> shapes {
        ShapeFactory::Create(ShapeType::Circle),
        ShapeFactory::Create(ShapeType::Box),
        ShapeFactory::Create(ShapeType::Circle) 
    };

    for (int i = 0; i < 10; i++) {
        int whichShape = rand() % 100;
        if (whichShape < 50) 
            shapes.push_back(ShapeFactory::Create(ShapeType::Circle));
        else 
            shapes.push_back(ShapeFactory::Create(ShapeType::Box));
    }

    cout << "--------------------------------------------------" << endl << endl;;
    for (auto s: shapes) {
        s->draw();
    }
    cout << "--------------------------------------------------" << endl << endl;;

}

#endif

