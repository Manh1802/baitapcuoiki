#include <iostream>
#include <vector>
using namespace std;

class MayLoc
{
protected:
    double congSuat;

public:
    MayLoc(double congSuat) : congSuat(congSuat) {}

    virtual double tinhChiPhi(double thoiGianHoatDong) = 0;
    double getCongSuat()
    {
        return congSuat;
    }
};

class MayLyTam : public MayLoc
{
private:
    double luongXang;

public:
    MayLyTam(double congSuat, double luongXang) : MayLoc(congSuat), luongXang(luongXang) {}

    double tinhChiPhi(double thoiGianHoatDong) override
    {
        double chiPhiThue = 50000 * thoiGianHoatDong; // Đơn giá thuê máy ly tâm
        double chiPhiNhienLieu = luongXang * 20000;   // Đơn giá xăng
        return chiPhiThue + chiPhiNhienLieu;
    }
};

class MayXucTac : public MayLoc
{
private:
    double luongHoaChat;

public:
    MayXucTac(double congSuat, double luongHoaChat) : MayLoc(congSuat), luongHoaChat(luongHoaChat) {}

    double tinhChiPhi(double thoiGianHoatDong) override
    {
        double chiPhiThue = 80000 * thoiGianHoatDong; // Đơn giá thuê máy xúc tác
        double chiPhiNhiemVu = luongHoaChat * 10000;  // Đơn giá hóa chất
        return chiPhiThue + chiPhiNhiemVu;
    }
};

int main()
{
    int n;    // Số lượng máy lọc
    double M; // Lượng nước trong ao (m3)

    cout << "Nhap so luong may loc: ";
    cin >> n;

    vector<MayLoc *> mayLocList;

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin may loc thu " << i + 1 << ":\n";
        int loaiMay;
        double congSuat;
        double luongNhiemVu; // Xăng hoặc hóa chất tùy thuộc vào loại máy

        cout << "Loai may (1: May Ly Tam, 2: May Xuc Tac): ";
        cin >> loaiMay;

        cout << "Cong suat (m3/h): ";
        cin >> congSuat;

        cout << "Luong nhien vu (g hoac lit): ";
        cin >> luongNhiemVu;

        if (loaiMay == 1)
        {
            mayLocList.push_back(new MayLyTam(congSuat, luongNhiemVu));
        }
        else if (loaiMay == 2)
        {
            mayLocList.push_back(new MayXucTac(congSuat, luongNhiemVu));
        }
    }

    cout << "Nhap luong nuoc trong ao (m3): ";
    cin >> M;

    double totalCost = 0.0;

    for (MayLoc *mayLoc : mayLocList)
    {
        totalCost += mayLoc->tinhChiPhi(M / mayLoc->getCongSuat());
    }

    if (totalCost > 0)
    {
        cout << "Tong chi phi su dung may loc: " << totalCost << " VND" << endl;
    }
    else
    {
        cout << "Ao khong duoc loc sach." << endl;
    }

    // Giải phóng bộ nhớ
    for (MayLoc *mayLoc : mayLocList)
    {
        delete mayLoc;
    }

    return 0;
}