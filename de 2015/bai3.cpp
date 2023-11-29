#include <iostream>
#include <vector>
#include <string>

// Lớp cơ sở cho mọi loại sạp
class Stall
{
protected:
    int stallNumber;
    double area;

public:
    Stall(int number, double a) : stallNumber(number), area(a) {}

    virtual double calculateRent() const = 0;                   // Phương thức ảo pure để tính tiền thuê sạp
    virtual double calculateTax() const = 0;                    // Phương thức ảo pure để tính thuế doanh thu
    virtual double calculateAdditionalFee() const { return 0; } // Phương thức ảo để tính chi phí thêm (nếu có)
};

// Lớp con cho sạp thực phẩm
class FoodStall : public Stall
{
private:
    double coldStorageFee;

public:
    FoodStall(int number, double a, double coldFee)
        : Stall(number, a), coldStorageFee(coldFee) {}

    double calculateRent() const override
    {
        return 40000000 * area + calculateAdditionalFee();
    }

    double calculateTax() const override
    {
        return 0.05;
    }

    double calculateAdditionalFee() const override
    {
        return coldStorageFee;
    }
};

// Lớp con cho sạp quần áo
class ClothingStall : public Stall
{
public:
    ClothingStall(int number, double a) : Stall(number, a) {}

    double calculateRent() const override
    {
        return 40000000 * area;
    }

    double calculateTax() const override
    {
        return 0.10;
    }
};

// Lớp con cho sạp trang sức
class JewelryStall : public Stall
{
private:
    double revenue;

public:
    JewelryStall(int number, double a, double rev)
        : Stall(number, a), revenue(rev) {}

    double calculateRent() const override
    {
        return 40000000 * area;
    }

    double calculateTax() const override
    {
        if (revenue < 100000000)
        {
            return 0.20;
        }
        else
        {
            return 0.30;
        }
    }
};

int main()
{
    std::vector<Stall *> stalls;

    // Nhập thông tin các sạp
    // ...

    // Tính tổng số tiền các sạp phải đóng hàng năm
    double totalAmount = 0;
    for (const auto &stall : stalls)
    {
        totalAmount += stall->calculateRent() + stall->calculateRent() * stall->calculateTax();
    }

    std::cout << "Total amount to be paid annually: " << totalAmount << " VND" << std::endl;

    // Giải phóng bộ nhớ
    for (const auto &stall : stalls)
    {
        delete stall;
    }

    return 0;
}