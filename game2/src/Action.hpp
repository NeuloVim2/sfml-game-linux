#ifndef ACTION_H
#define ACTION_H

#include <SFML/Window/Event.hpp>

class Action
{
public:
	enum Name
	{
		NAME_NONE,
		UP,
		DOWN,
		PLAY,
		QUIT
	};

	enum Phase 
	{
		PHASE_NONE,
		START,
		END
	};

private:
	Name m_name{ Name::NAME_NONE };
	Phase m_phase{ Phase::PHASE_NONE };

public:
	Action() = default;
	~Action() = default;
	Action(const Name name, const Phase Phase)
		: m_name(name), m_phase(Phase)
	{};

	const Name& name() const
	{
		return m_name;
	};

	const Phase& phase() const
	{
		return m_phase;
	};
};

#endif