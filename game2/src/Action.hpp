#ifndef ACTION_H
#define ACTION_H

#include <SFML/Window/Event.hpp>

class Action
{
public:
	enum Name
	{
		NONE,
		Up
	};

	enum Phase 
	{
		NONE,
		START,
		END
	};

private:
	Name m_name{ Name::NONE };
	Phase m_Phase{ Phase::NONE };

public:
	Action() = default;
	~Action() = default;
	Action(const Name name, const Phase Phase)
		: m_name(name), m_Phase(Phase)
	{};

	const Name& name() const
	{
		return m_name;
	};

	const Phase& phase() const
	{
		return m_Phase;
	};
};

#endif