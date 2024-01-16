#pragma once

class Visitor;
class VisitorTable;

class Visitee
{
public:
	virtual void accept(Visitor&) = 0;
};

