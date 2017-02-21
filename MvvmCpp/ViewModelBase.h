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

		template<typename T>
		void SetProperty(T& store, T const value, Platform::String^ propertyName = "") {
			if (store != value)
			{
				T oldValue = store;
				try {
					store = value;
					OnPropertyChanged(propertyName);
				}
				catch (Exception^ ex) {
					store = oldValue;
					throw ex;
				}
			}
		}

		bool m_isBusy;
	};
}