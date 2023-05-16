#pragma once

#include "AseraiEngine/Core/EventManager.h"
#include "AseraiEngine/Core/InputManager.h"

#include <string>

struct GLFWwindow;

namespace Aserai
{
	struct WindowProperties
	{
		std::string Name;
		uint32_t Width;
		uint32_t Height;
		bool VSync;
	};

	class Window
	{
	public:
		Window();

		bool Init(const WindowProperties& props);
		void Destroy();
		void Update();
		
		const WindowProperties& GetProperties() const;
		void SetProperties(const WindowProperties& props);
		bool IsVSync() const;
		void SetVSync(bool vsync);
		uint32_t GetWidth() const;
		uint32_t GetHeight() const;
		inline const auto* GetNativeWindow() const { return m_NativeWindow; }

		void SetupWindowEvents(const std::shared_ptr<EventManager>& eventManager);
		void SetupInputEvents(const std::shared_ptr<InputManager>& inputManager);

	private:
		bool InitContext();

	private:
		struct WindowPrivateData
		{
			std::string Name;
			uint32_t Width;
			uint32_t Height;
			bool VSync;
			std::shared_ptr<EventManager> EventManager;
			std::shared_ptr<InputManager> InputManager;
		};

		bool m_Initialized;
		GLFWwindow* m_NativeWindow;
		WindowPrivateData m_WinPrivData;
	};
}
