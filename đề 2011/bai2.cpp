#include <iostream>
using namespace std;

class MayXucTac
{
private:
    static const int DON_GIA_THUE = 80000;     // Đơn giá thuê máy (đồng/giờ)
    static const int DON_GIA_HOA_CHAT = 10000; // Đơn giá hóa chất (đồng/g)
    double congSuat;                           // Công suất lọc (m3/h)
    double thoiGianHoatDong;                   // Thời gian hoạt động (giờ)
    double luongHoaChat;                       // Lượng hóa chất (g)

public:
    // Hàm khởi tạo mặc định
    MayXucTac()
    {
        congSuat = 0.0;
        thoiGianHoatDong = 0.0;
        luongHoaChat = 0.0;
    }
    // Hàm nhập dữ liệu
    void nhap()
    {
        cout << "Nhap cong suat loc (m3/h): ";
        cin >> congSuat;
        cout << "Nhap thoi gian hoat dong (giờ): ";
        cin >> thoiGianHoatDong;
        cout << "Nhap luong hoa chat (g): ";
        cin >> luongHoaChat;
    }
    // Hàm tính lượng nước
    double tinhLuongNuoc()
    {
        double luongNuoc = 0.0;
        if (thoiGianHoatDong < 10)
        {
            luongNuoc = congSuat * (luongHoaChat / 100);
        }
        else
        {
            luongNuoc = congSuat * (luongHoaChat / 100) / (thoiGianHoatDong / 10);
        }
        return luongNuoc;
    }
    // Hàm tính chi phí

    double tinhChiPhi()
    {
        double chiPhiThue = DON_GIA_THUE * thoiGianHoatDong;
        double chiPhiHoaChat = DON_GIA_HOA_CHAT * luongHoaChat;
        return chiPhiThue + chiPhiHoaChat;
    }
};

int main()
{
    // Khởi tạo đối tượng MayXucTac
    MayXucTac m;
    // Gọi đến hàm nhập thông tin
    m.nhap(); // Nhập thông tin sử dụng của máy xúc tác này
    // Hàm tính chi phí sử dụng
    cout << "Chi phi su dung may: " << m.tinhChiPhi() << " VND" << endl;
    // Hàm tính lượng nước sử dụng
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << " m3" << endl;
    return 0;
}