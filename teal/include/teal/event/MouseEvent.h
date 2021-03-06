#pragma once

#include "Event.h"

namespace Teal
{
	class TL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y, float rawx, float rawy) : _X(x), _Y(y), _RawX(rawx), _RawY(rawy) {}

		float GetRawX() const { return _RawX; }
		float GetRawY() const { return _RawY; }
		float GetX() const { return _X; }
		float GetY() const { return _Y; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << " " << _X << "," << _Y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(ECMouse | ECInput)
	private:
		float _X, _Y, _RawX, _RawY;
	};

	class TL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y) : _X(x), _Y(y) {}

		float GetX() const { return _X; }
		float GetY() const { return _Y; }

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(ECMouse | ECInput)
	private:
		float _X, _Y;
	};

	class TL_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return _Button; }

		EVENT_CLASS_CATEGORY(ECMouseButton | ECMouse | ECInput)
	protected:
		MouseButtonEvent(int button) : _Button(button) {}
		int _Button;
	};

	class TL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class TL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}