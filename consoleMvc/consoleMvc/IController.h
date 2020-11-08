#pragma once
class IVisitor {
public:
	virtual void update() = 0;
};


class Visitor: