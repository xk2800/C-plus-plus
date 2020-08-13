#include <iostream>
#include<iomanip>

using namespace std;

class Manisan{

    int KacangHijau, JagungDurian, PulutHitam, SantanMango, Pudding, Fruits;
    float price;

    public:
        void Bubur_Manisan(int KH, int JD, int PH, int SM, int P, int F){

            KacangHijau = KH;
            JagungDurian = JD;
            PulutHitam = PH;
            SantanMango = SM;
            Pudding = P;
            Fruits = F;

            ManisanOrder();
        }

        void ManisanOrder(){

            int totalbowls;

            cout<<endl<<"Here Your Bubur/Manisan Order List"<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<endl<<"Bubur Kacang Hijau\t:"<<KacangHijau<<" bowl(s)";
            cout<<endl<<"Bubur Jagung + Durian\t:"<<JagungDurian<<" bowl(s)";
            cout<<endl<<"Bubur Pulut Hitam\t:"<<PulutHitam<<" bowl(s)";
            cout<<endl<<"Pulut, Santan & Mango\t:"<<SantanMango<<" bowl(s)";
            cout<<endl<<"Creamy Marble Pudding\t:"<<Pudding<<" bowl(s)";
            cout<<endl<<"Fresh Mix Local Fruits\t: "<<Fruits<<" bowl(s)";

            totalbowls=KacangHijau + JagungDurian + PulutHitam + SantanMango + Pudding + Fruits;

            cout<<endl<<endl<<">>Total bowls\t:"<<totalbowls<<endl;

        }

        void calcPrice(){

            float priceKH = KacangHijau * 2.5;
            float priceJD = JagungDurian * 4.5;
            float pricePH = PulutHitam * 2.5;
            float priceSM = SantanMango * 4.5;
            float priceP = Pudding * 2;
            float priceF = Fruits * 2;

            float totalprice = priceKH + priceJD + pricePH + priceSM + priceP + priceF;

            cout<<setprecision(2)<<">>Thank you. Your order price is RM "<<fixed<<totalprice;

        }

};

int main(){

    Manisan BM;

    char select;
    int KH, JD, PH, SM, P, F;


    cout<<"---------------------------------------"<<endl<<"\t++ Bubur & Manisan Stall ++"<<endl<<"---------------------------------------"<<endl;
    cout<<"Looking for a yummy Bubur/Manisan? [Y/N]"<<endl;
        cin>>select;

    while(select=='Y'){

        cout<<endl<<"........Yummy Bubur & Manisan Selection........"<<endl;
        cout<<"[1] Bubur Kacang Hijau (bowl)\t\t: ";
            cin>>KH;
        cout<<"[2] Bubur Jagung + Durian  (bowl)\t: ";
            cin>>JD;
        cout<<"[3] Bubur Pulut Hitam (bowl)\t\t: ";
            cin>>PH;
        cout<<"[4] Pulut, Santan & Mango (bowl)\t: ";
            cin>>SM;
        cout<<"[5] Creamy Marble Pudding (bowl)\t: ";
            cin>>P;
        cout<<"[6] Fresh Mix Local Fruits (bowl)\t: ";
            cin>>F;

        cout<<endl<<"Please be seated. Your order will be served shortly..."<<endl;

        BM.Bubur_Manisan(KH, JD, PH, SM, P, F);
        BM.calcPrice();

        cout<<endl<<endl<<"Would you like to make another order? [Y/N]"<<endl;
            cin>>select;

    }

}