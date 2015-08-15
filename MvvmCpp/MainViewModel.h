#pragma once

#include "ViewModelBase.h" 

namespace MvvmCpp
{
	//ref class HubPhotoGroup;
	//interface class IPhoto;
	//class ExceptionPolicy;

	// See http://go.microsoft.com/fwlink/?LinkId=267276 for info on how view model classes interact  
	// with view classes (pages) and model classes (the state and operations of business objects). 

	// The MainHubViewModel class contains the presentation logic for the main hub page (MainHubView.xaml). 
	[Windows::UI::Xaml::Data::Bindable]
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class MainViewModel sealed : public Common::ViewModelBase
	{
	internal:
		MainViewModel();
		//MainHubViewModel(Windows::Foundation::Collections::IObservableVector<HubPhotoGroup^>^ photoGroups, std::shared_ptr<ExceptionPolicy> exceptionPolicy);

	public:
		virtual ~MainViewModel();

		//property Windows::Foundation::Collections::IObservableVector<HubPhotoGroup^>^ PhotoGroups
		//{
		//	Windows::Foundation::Collections::IObservableVector<HubPhotoGroup^>^ get();
		//}

		//property Windows::UI::Xaml::Input::ICommand^ NavigateToPicturesCommand
		//{
		//	Windows::UI::Xaml::Input::ICommand^ get();
		//}

		property Windows::UI::Xaml::Input::ICommand^ ButtonClickCommand
		{
			Windows::UI::Xaml::Input::ICommand^ get();
		}

		//property Windows::UI::Xaml::Input::ICommand^ RotateImageCommand
		//{
		//	Windows::UI::Xaml::Input::ICommand^ get();
		//}

		//property Windows::UI::Xaml::Input::ICommand^ CartoonizeImageCommand
		//{
		//	Windows::UI::Xaml::Input::ICommand^ get();
		//}
		
		property Platform::String^ Title
		{
			Platform::String^ get();
			void set(Platform::String^ value);
		}

	private:
		//Windows::Foundation::Collections::IObservableVector<HubPhotoGroup^>^ m_photoGroups;
		//Windows::UI::Xaml::Input::ICommand^ m_navigateToPicturesCommand;
		Windows::UI::Xaml::Input::ICommand^ m_ButtonClickCommand;
		//Windows::UI::Xaml::Input::ICommand^ m_rotateImageCommand;
		//Windows::UI::Xaml::Input::ICommand^ m_cartoonizeImageCommand;
		Platform::String^ m_title;
		//HubPhotoGroup^ m_pictureGroup;
		//Windows::Foundation::EventRegistrationToken m_pictureGroupPropertyChangedToken;

		//void NavigateToPictures(Platform::Object^ parameter);
		//bool CanNavigateToPictures(Platform::Object^ parameter);
		void OnButtonClicked(Platform::Object^ parameter);
		//void RotateImage(Platform::Object^ parameter);
		//void CartoonizeImage(Platform::Object^ parameter);
		bool IsValid(Platform::Object^ parameter);
		//void OnPictureGroupPropertyChanged(Platform::Object^ sender, Windows::UI::Xaml::Data::PropertyChangedEventArgs^ e);
	};
}