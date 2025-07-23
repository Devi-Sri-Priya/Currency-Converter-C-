#include<iostream>
using namespace std;

class CurrencyConvertor {
private:
    double usdToEuroRate;
    double euroToUsdRate;
    double usdToPakRupeeRate;
    double usdToIndRupeeRate;
    double usdToVndRate;

public:
    CurrencyConvertor(double usdToEuro, double euroToUsd, double usdToPak, double usdToInd, double usdToVnd) {
        usdToEuroRate = usdToEuro;
        euroToUsdRate = euroToUsd;
        usdToPakRupeeRate = usdToPak;
        usdToIndRupeeRate = usdToInd;
        usdToVndRate = usdToVnd;
    }

    // USD to others
    double usdToEuro(double usdAmount) {
        return usdAmount * usdToEuroRate;
    }

    double euroToUsd(double euroAmount) {
        return euroAmount * euroToUsdRate;
    }

    double usdToPakRupee(double usdAmount) {
        return usdAmount * usdToPakRupeeRate;
    }

    double usdToIndRupee(double usdAmount) {
        return usdAmount * usdToIndRupeeRate;
    }

    double usdToVND(double usdAmount) {
        return usdAmount * usdToVndRate;
    }

    // INR to others
    double inrToUsd(double inrAmount) {
        return inrAmount / usdToIndRupeeRate;
    }

    double inrToEuro(double inrAmount) {
        return inrToUsd(inrAmount) * usdToEuroRate;
    }

    double inrToPakRupee(double inrAmount) {
        return inrToUsd(inrAmount) * usdToPakRupeeRate;
    }

    double inrToVND(double inrAmount) {
        return inrToUsd(inrAmount) * usdToVndRate;
    }

    void displayExchangeRate() const {
        cout << "\n\t-------- Current Exchange Rates -----------\n";
        cout << "1 USD to Euro               : " << usdToEuroRate << endl;
        cout << "1 Euro to USD               : " << euroToUsdRate << endl;
        cout << "1 USD to Pakistani Rupee    : " << usdToPakRupeeRate << endl;
        cout << "1 USD to Indian Rupee       : " << usdToIndRupeeRate << endl;
        cout << "1 USD to Vietnamese Dong    : " << usdToVndRate << endl;
    }
};

int main() {
    const double initialUsdToEuroRate = 0.85;
    const double initialEuroToUsdRate = 1.18;
    const double initialUsdToPakRate = 277.50;
    const double initialUsdToIndRate = 75.00;
    const double initialUsdToVndRate = 24500.00;

    CurrencyConvertor convertor(initialUsdToEuroRate, initialEuroToUsdRate, initialUsdToPakRate, initialUsdToIndRate, initialUsdToVndRate);

    int choice;
    double amount;

    do {
        system("cls");
        convertor.displayExchangeRate();
        cout << "\n\t******* Currency Convertor Main Menu ********\n";
        cout << "1. Convert USD to Euro\n";
        cout << "2. Convert Euro to USD\n";
        cout << "3. Convert USD to Pakistani Rupee\n";
        cout << "4. Convert USD to Indian Rupee\n";
        cout << "5. Convert USD to Vietnamese Dong\n";
        cout << "6. Convert Indian Rupee to USD\n";
        cout << "7. Convert Indian Rupee to Euro\n";
        cout << "8. Convert Indian Rupee to Pakistani Rupee\n";
        cout << "9. Convert Indian Rupee to Vietnamese Dong\n";
        cout << "0. Exit\n";
        cout << "Please Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the Amount in USD: ";
            cin >> amount;
            cout << amount << " USD = " << convertor.usdToEuro(amount) << " Euro\n";
            system("pause");
            break;
        case 2:
            cout << "Enter the Amount in Euro: ";
            cin >> amount;
            cout << amount << " Euro = " << convertor.euroToUsd(amount) << " USD\n";
            system("pause");
            break;
        case 3:
            cout << "Enter the Amount in USD: ";
            cin >> amount;
            cout << amount << " USD = " << convertor.usdToPakRupee(amount) << " Pakistani Rupee\n";
            system("pause");
            break;
        case 4:
            cout << "Enter the Amount in USD: ";
            cin >> amount;
            cout << amount << " USD = " << convertor.usdToIndRupee(amount) << " Indian Rupee\n";
            system("pause");
            break;
        case 5:
            cout << "Enter the Amount in USD: ";
            cin >> amount;
            cout << amount << " USD = " << convertor.usdToVND(amount) << " Vietnamese Dong\n";
            system("pause");
            break;
        case 6:
            cout << "Enter the Amount in Indian Rupee: ";
            cin >> amount;
            cout << amount << " INR = " << convertor.inrToUsd(amount) << " USD\n";
            system("pause");
            break;
        case 7:
            cout << "Enter the Amount in Indian Rupee: ";
            cin >> amount;
            cout << amount << " INR = " << convertor.inrToEuro(amount) << " Euro\n";
            system("pause");
            break;
        case 8:
            cout << "Enter the Amount in Indian Rupee: ";
            cin >> amount;
            cout << amount << " INR = " << convertor.inrToPakRupee(amount) << " Pakistani Rupee\n";
            system("pause");
            break;
        case 9:
            cout << "Enter the Amount in Indian Rupee: ";
            cin >> amount;
            cout << amount << " INR = " << convertor.inrToVND(amount) << " Vietnamese Dong\n";
            system("pause");
            break;
        case 0:
            cout << "Exiting Program...\n";
            break;
        default:
            cout << "Invalid Choice! Please try again.\n";
            system("pause");
        }
    } while (choice != 0);

    return 0;
}

