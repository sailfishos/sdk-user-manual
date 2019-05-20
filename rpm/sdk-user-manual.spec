Name: sdk-user-manual
Version: 1
Release: 1
Summary: Sailfish SDK User Manual
Group: Documentation
License: CC BY-NC-SA 3.0 / BSD
URL: https://github.com/sailfishos/sdk-user-manual
Source: %{name}-%{version}.tar.bz2

%description
Documentation for introducing users to the Sailfish SDK. Details how to create
Sailfish Applications using the libsafailfishapp support library.

%package doc
Summary: Documentation for %{name}.
BuildRequires: mer-qdoc-template

%description doc
This package contains the documentation for %{name}.

%package examples
Summary: Documentation examples for %{name}.
BuildRequires:  pkgconfig(sailfishapp) >= 1.0.2
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5Qml)
BuildRequires:  pkgconfig(Qt5Quick)
BuildRequires:  desktop-file-utils

%description examples
This package contains the example applications built for the documentation
for %{name}.

%prep
%setup -q

%build
%qmake5 -r VERSION=%{version}
make

%install
make install INSTALL_ROOT=%{buildroot}
mkdir -p %{buildroot}/%{_docdir}/%{name}
cp -R doc/html/* %{buildroot}/%{_docdir}/%{name}/

%files doc
%defattr(-,root,root,-)
%{_docdir}/%{name}

%files examples
%defattr(-,root,root,-)
%{_bindir}
%{_datadir}/harbour-demo
%{_datadir}/harbour-demo-02
%{_datadir}/harbour-demo-03
%{_datadir}/harbour-demo-04
%{_datadir}/harbour-demo-05
%{_datadir}/harbour-demo-06
%{_datadir}/harbour-demo-07
%{_datadir}/harbour-demo-11
%{_datadir}/harbour-demo-12
%{_datadir}/harbour-demo-13
%{_datadir}/applications/harbour-demo.desktop
%{_datadir}/icons/hicolor/*/apps/harbour-demo.png
# >> files
# << files
