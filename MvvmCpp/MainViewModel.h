#pragma once

#include "ViewModelBase.h" 

namespace MvvmCpp
{
	[Windows::UI::Xaml::Data::Bindable]
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class MainViewModel sealed : public Common::ViewModelBase
	{
	internal:
		MainViewModel();
		
	public:
		virtual ~MainViewModel();

		property Windows::UI::Xaml::Input::ICommand^ ButtonClickCommand
		{
			Windows::UI::Xaml::Input::ICommand^ get();
		}

		property Platform::String^ Title
		{
			Platform::String^ get();
			void set(Platform::String^ value);
		}

		bool IsValid(Platform::Object^ parameter);

	private:
		Windows::UI::Xaml::Input::ICommand^ m_ButtonClickCommand;
		Platform::String^ m_title;

		void OnButtonClicked(Platform::Object^ parameter);
	};
}