#pragma once

#include "BindableBase.h" 

namespace Common
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ViewModelBase : public Common::BindableBase
	{
	internal:
		ViewModelBase();

		virtual void LoadState(Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ stateMap);
		virtual void SaveState(Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ stateMap);
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e);
		virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e);

	public:
		property bool IsBusy { bool get(); void set(bool value); }

	protected private:

		bool m_isBusy;
	};
}