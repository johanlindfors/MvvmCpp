#include "pch.h" 
#include "ViewModelBase.h" 

using namespace Common;
using namespace Platform;
using namespace std;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml::Navigation;

ViewModelBase::ViewModelBase()
	: m_isBusy(false)
{
}

bool ViewModelBase::IsBusy::get()
{
	return m_isBusy;
}

void ViewModelBase::IsBusy::set(bool value)
{
	if (m_isBusy != value)
	{
		bool oldValue = m_isBusy;
		try {
			m_isBusy = value;
			OnPropertyChanged("IsBusy");
		}
		catch (Exception^ ex) {
			m_isBusy = oldValue;
			throw ex;
		}
	}
}

void ViewModelBase::OnNavigatedTo(NavigationEventArgs^ e)
{
}

void ViewModelBase::OnNavigatedFrom(NavigationEventArgs^ e)
{
}

void ViewModelBase::LoadState(IMap<String^, Object^>^ stateMap)
{
}

void ViewModelBase::SaveState(IMap<String^, Object^>^ stateMap)
{
}