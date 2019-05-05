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

