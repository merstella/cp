#include <iostream>
#include <string>

int main() {
    // Mảng ký tự chứa chuỗi "HANOI Vietnam ABC1234562!@#%cnXYZ"
    std::string str = "HANOI Vietnam ABC1234562!@#%cnXYZ";

    // Khởi tạo các giá trị tương ứng
    char a0 = 0x41; // 'A'
    char a1 = 0x5A; // 'Z'
    int s3 = 0;     // Bộ đếm số ký tự chữ cái in hoa
    int s0 = 0;     // Chỉ số của ký tự đang xét

    // Vòng lặp để duyệt qua chuỗi
    while (true) {
        char s1 = str[s0]; // Lấy ký tự hiện tại tại vị trí s0
        if (s1 == '\0') { // Kiểm tra kết thúc chuỗi
            break;         // Thoát vòng lặp nếu gặp ký tự null
        }
        if (s1 >= a0 && s1 <= a1) { // Kiểm tra ký tự là chữ cái in hoa
            s3++;                  // Tăng bộ đếm nếu là chữ cái in hoa
        }
        s0++; // Tăng chỉ số để xét ký tự tiếp theo
    }

    // In ra số lượng ký tự in hoa
    std::cout << "Number of uppercase letters: " << s3 << std::endl;

    return 0;
}
