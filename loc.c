#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Tkinter.h>
#include <phonenumbers/phonenumberutil.h>
#include <folium/folium.h>
#include <geopy/geocoders/nominatim.h>
#include <phonenumbers/geocoder.h>
#include <phonenumbers/timezone.h>
#include <opencage/geocoder.h>

int main() {
    Tkinter::Tk a;
    a.title("LOCATION DETECTOR");
    a.configure(bg="black");
    a.geometry("750x1200");
    Tkinter::Label l1(a, text="Location Tracker", font=("times new roman", 30), bg="black", fg="white");
    l1.pack();
    Tkinter::Label l2(a, text="Enter Phone Number :", font=("times new roman", 20), bg="black", fg="white");
    l2.place(x=250, y=80);
    Tkinter::Entry e1(a, width=40);
    e1.place(x=250, y=120);
    a.resizable(False, False);
    auto call = [&]() {
        phonenumbers::PhoneNumberUtil phonenumbers;
        folium::Folium folium;
        geopy::geocoders::Nominatim geopy;
        phonenumbers::PhoneNumberUtil::PhoneNumber samnumber;
        std::string key = "7f7e22d3a52f4f4aa06ae46543ef5b07";
        std::string number = e1.get();
        phonenumbers.parse(number, samnumber);
        std::string yourlocation = phonenumbers::geocoder::description_for_number(samnumber, "en");
        std::string timezone = phonenumbers::timezone::time_zones_for_number(samnumber);
        Tkinter::Label l3(a, text=" ", bg="black", fg="white", font=("times new roman", 18));
        l3.place(x=230, y=220);
        l3.configure(text=yourlocation);
        Tkinter::Label l8(a, text=" ", bg="black");
        l8.place(x=230, y=300);
        phonenumbers::PhoneNumber service_provider;
        phonenumbers.parse(number, "RO", service_provider);
        std::string sp = phonenumbers::carrier::name_for_number(service_provider, "en");
        Tkinter::Label l4(a, text=" ", bg="black", fg="white", font=("times new roman", 18));
        l4.place(x=230, y=250);
        l4.configure(text=sp);
        Tkinter::Label l5(a, text=" ", bg="black", fg="white", font=("times new roman", 18));
        l5.place(x=230, y=280);
        l5.configure(text=timezone);
        opencage::geocoder::OpenCageGeocode geocoder(key);
        std::string query = std::to_string(number);
    };
    return 0;
}
