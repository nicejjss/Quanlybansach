#include <iostream>
#include <bits/stdc++.h>
#include<fstream>
using namespace std;


//struct sach lien ket don
struct Sach
{
    char ma[30];
    char ten[50];
    char theloai[30];
    float dongia;
};
//tao struct Node Sach
struct NodeSach
{
    Sach infor;
    struct NodeSach *next;
};
//tao list Sach
struct ListSach
{
    NodeSach *Head;
    NodeSach *Tail;
};
//Khoi tao danh sach sach
void KhoiTaoDSSach(ListSach &L)
{
    L.Head=NULL;
    L.Tail=NULL;
}
bool CheckEmpty(ListSach &L)
{
    if(L.Head==NULL) return 1;
    else return 0;
}

//Khoi tao Node Sach
NodeSach *Get_NodeSach(Sach x)
{
    NodeSach *p=new NodeSach;
    if(p==NULL)
    {
        cout<<"Het bo nho de su dung!!!";
        return NULL;
    }
    p->infor=x;
    p->next=NULL; //Mới khai báo NODE nên không liên kết với các NODE khác
    return p;
}
//Chen Node Vao cuoi ds
void InsertLastSach(ListSach &L,NodeSach *p)
{
    if(L.Head==NULL)
    {
        L.Head=p;
        L.Tail=L.Head;
    }
    else
    {
        L.Tail->next=p;
        L.Tail=p;
    }
}

//Nhap sach
void NhapSach(Sach &x)
{
    cout<<"\nNhap ma: ";
    gets(x.ma);
    fflush(stdin);
    cout<<"\nNhap ten: ";
    gets(x.ten);
    fflush(stdin);
    cout<<"\nNhap the loai: ";
    gets(x.theloai);
    fflush(stdin);
    cout<<"\nNhap don gia: ";
    cin>>x.dongia;
    fflush(stdin);
}
//Nhap dsSach
void NhapDSSach(ListSach &L)
{
    int sl;
    NodeSach *p;
    Sach x;
    cout<<"\nNhap so sach: ";
    cin>>sl;
    fflush(stdin);
    for(int i=0; i<sl; i++)
    {
        cout<<"Sach thu "<<i+1;
        NhapSach(x);
        p=Get_NodeSach(x);
        InsertLastSach(L,p);
    }
}
void TableSach()
{
    cout<<"\n"<<setw(10)<<"Ma Sach"<<setw(20)<<"Ten Sach"<<setw(20)<<"The Loai"<<setw(20)<<"Don Gia";
}
void HienSach(NodeSach *p)
{
    cout<<"\n"<<setw(10)<<p->infor.ma<<setw(20)<<p->infor.ten<<setw(20)<<p->infor.theloai<<setw(20)<<p->infor.dongia;

}
//hien dssach
void HienListSach(ListSach L)
{
    NodeSach *p;
    TableSach();
    for(p=L.Head; p!=NULL; p=p->next)
    {
        HienSach(p);
    }

}

void SapXepSachTheoDonGia(ListSach &L)
{
    NodeSach *p;
    NodeSach *n;
    for(p=L.Head; p!=NULL; p=p->next)
    {
        for(n=p->next; n!=NULL; n=n->next)
        {
            if(p->infor.dongia>n->infor.dongia)
            {
                Sach tg=p->infor;
                p->infor=n->infor;
                n->infor=tg;
            }
        }

    }
    cout<<"\nSau khi Sap Xep!";
    HienListSach(L);
}
NodeSach* Get_NodeTenSach(ListSach L,char tten[])
{
    NodeSach *p;
    for(p=L.Head; p!=NULL; p=p->next)
    {
        if(strcmp(p->infor.ten,tten) == 0)
        {
            return p;
        }

    }
    return NULL;
}
void TimKiemSachTheoTen(ListSach L)
{
    char tten[30];
    cout<<"\nNhap ten can tim: ";
    gets(tten);
    fflush(stdin);
    NodeSach *p=Get_NodeTenSach(L,tten);
    if(p!=NULL)
    {
        cout<<"\nSach Da Tim Thay: ";
        TableSach();
        HienSach(p);
    }
    else
    {
        cout<<"\nKhong tim thay Sach!!!";
    }
}

void XoaPhanTuDau(ListSach &L)
{
    NodeSach *p=new NodeSach;
    if(L.Head!=NULL)
    {
        p=L.Head;
        L.Head=L.Head->next;
        delete p;
        if(L.Head==NULL)
            L.Tail=NULL;
    }
}
void XoaPhanTuCuoi(ListSach &L)
{
    for(NodeSach *p=L.Head; p!=NULL; p=p->next)
    {
        if(p->next==L.Tail)
        {
            delete L.Tail;
            p->next=NULL;
            L.Tail=p;
        }
    }
}
void XoaPhieuSachTheoTen(ListSach &L)
{
    NodeSach *ak=new NodeSach;
    char tten[30];
    cout<<"\nNhap Ten Sach de xoa: ";
    gets(tten);
    fflush(stdin);
    int d=0;
    for(NodeSach *p=L.Head; p!=NULL; p=p->next)
    {
        if(strcmp(p->infor.ten,tten)==0)
        {
            d++;
        }
    }
    if(d==0)
    {
        cout<<"\nKhong co Sach Nay!!";
    }
    else
    {
        if(strcmp(L.Head->infor.ten,tten)==0)
        {
            XoaPhanTuDau(L);
            HienListSach(L);
        }
        else if(strcmp(L.Tail->infor.ten,tten)==0)
        {
            XoaPhanTuCuoi(L);
            HienListSach(L);
        }
        else
        {
            for(NodeSach *k=L.Head; k!=NULL; k=k->next)
            {
                ak=k->next;
                if(strcmp(ak->infor.ten,tten)==0)
                {
                    k->next=ak->next;
                    break;
                }
            }
            delete ak;
            HienListSach(L);
        }
    }
}


//sua gia sach theo ten

void SuaGiaSachTheoTen(ListSach &L)
{
    float giam;
    char tten[30];
    cout<<"\nNhap ten can sua: ";
    gets(tten);
    fflush(stdin);
    NodeSach *p=Get_NodeTenSach(L,tten);
    if(p!=NULL)
    {
        cout<<"\nNhap Gia can sua: ";
        cin>>giam;
        fflush(stdin);
        p->infor.dongia=giam;
        cout<<"\nSau khi sua Gia cho Sach Ten: "<<p->infor.ten;
        HienListSach(L);
    }
    else
    {
        cout<<"Khong co Sach nay de sua";
    }

}

void LuuFileSach(ListSach L)
{
    if(L.Head==NULL)
    {
        cout<<"Khong co du lieu luu!!!";
    }
    else
    {
        FILE *f ;
        f=fopen("Sach.dat","wb");
        NodeSach *p=L.Head;
        while(p!=NULL)
        {
            Sach *x=&(p->infor);
            fwrite(x,sizeof(Sach),1,f);
            p=p->next;
        }
        fclose(f);
        cout<<"\nDa luu file thanh cong";
    }
}

void DocFileSach(ListSach &S)
{
    if(CheckEmpty(S))
    {
        struct Sach n;
        FILE *f=fopen("Sach.dat","rb");
        while(fread(&n,sizeof(Sach),1,f))
        {
            NodeSach *p=Get_NodeSach(n);
            InsertLastSach(S,p);
        }
        fclose(f);
        HienListSach(S);
    }
    else
    {
        ListSach Q;
        KhoiTaoDSSach(Q);
        struct Sach n;
        FILE *f=fopen("Sach.dat","rb");
        while(fread(&n,sizeof(Sach),1,f))
        {
            NodeSach *p=Get_NodeSach(n);
            InsertLastSach(Q,p);
        }
        fclose(f);
        HienListSach(Q);
    }
}

//struct KhachHang LKDoi
struct KhachHang
{
    int ma;
    char ten[50],diachi[50],sdt[15];
};
struct NodeKhachHang
{
    KhachHang infor;
    NodeKhachHang *next;
};
struct ListKhachHang
{
    NodeKhachHang *Head;
    NodeKhachHang *Tail;
};
void KhoiTaoDSKhachHang(ListKhachHang &L)
{
    L.Head=NULL;
    L.Tail=NULL;
}
bool CheckEmpty(ListKhachHang &L)
{
    if(L.Head==NULL) return 1;
    else return 0;
}
NodeKhachHang* Get_NodeKhachHang(KhachHang x)
{
    NodeKhachHang *p=new NodeKhachHang;
    if(p==NULL)
    {
        cout<<"Het bo nho de su dung!!!";
        return NULL;
    }
    p->infor=x;
    p->next=NULL; //Mới khai báo NODE nên không liên kết với các NODE khác
    return p;
}
void InsertLastKhachHang(ListKhachHang &L,NodeKhachHang *p)
{
    if(L.Head==NULL)
    {
        L.Head=p;
        L.Tail=L.Head;
    }
    else
    {
        L.Tail->next=p;
        L.Tail=p;
    }
}
bool Get_NodeMaKhachHang(ListKhachHang L,int tma);
void NhapKhachHang(KhachHang &x,ListKhachHang K)
{
    bool co;
    do
    {
        cout<<"\nNhap maKH(So): ";
        cin>>x.ma;
        fflush(stdin);
        co=Get_NodeMaKhachHang(K,x.ma);
        if(co)
        {
            cout<<"\nDa co Khach Hang Trung Ma!!!";
        }
    }
    while(co==true);
    cout<<"\nNhap tenKH: ";
    gets(x.ten);
    fflush(stdin);
    cout<<"\nNhap SDT: ";
    gets(x.sdt);
    fflush(stdin);
    cout<<"\nNhap dia chi: ";
    gets(x.diachi);
    fflush(stdin);
}
//Nhap dsKH
void NhapDSKhachHang(ListKhachHang &L)
{
    int sl;
    NodeKhachHang *p;
    KhachHang x;
    cout<<"\nNhap so KH: ";
    cin>>sl;
    fflush(stdin);
    for(int i=0; i<sl; i++)
    {
        cout<<"KH thu "<<i+1;
        NhapKhachHang(x,L);
        p=Get_NodeKhachHang(x);
        InsertLastKhachHang(L,p);
    }
}

void TableKhachHang()
{
    cout<<"\n"<<setw(20)<<"Ma Khach Hang"<<setw(20)<<"Ten Khach Hang"<<setw(20)<<"SDT"<<setw(20)<<"Dia Chi";
}
void HienKhachHang(NodeKhachHang *p)
{
    cout<<"\n"<<setw(20)<<p->infor.ma<<setw(20)<<p->infor.ten<<setw(20)<<p->infor.sdt<<setw(20)<<p->infor.diachi;
}
//hien dssach
void HienListKhachHang(ListKhachHang L)
{
    NodeKhachHang *p;
    TableKhachHang();
    for(p=L.Head; p!=NULL; p=p->next)
    {
        HienKhachHang(p);
    }
}
//void DuyetListKhachHang(ListKhachHang L)
//{
//    NodeKhachHang *p;
//    TableKhachHang();
//    for(p=L.Head; p!=NULL; p=p->next)
//    {
//        cout<<"\n"<<setw(20)<<p->infor.ma<<setw(20)<<p->infor.ten<<setw(20)<<p->infor.sdt<<setw(20)<<p->infor.diachi;
//    }
//}
void SapXepKhachHangTheoMa(ListKhachHang &L)
{
    NodeKhachHang *p;
    NodeKhachHang *n;
    for(p=L.Head; p!=NULL; p=p->next)
    {
        for(n=p->next; n!=NULL; n=n->next)
        {
            if(p->infor.ma>n->infor.ma)
            {
                KhachHang tmp;
                tmp=p->infor;
                p->infor=n->infor;
                n->infor=tmp;
            }
        }
    }
}
NodeKhachHang* Get_NodeTenKhachHang(ListKhachHang L,char tten[])
{
    NodeKhachHang *p;
    for(p=L.Head; p!=NULL; p=p->next)
    {
        if(strcmp(p->infor.ten,tten)==0)
        {
            return p;
        }

    }
    return NULL;
}
bool Get_NodeMaKhachHang(ListKhachHang L,int tma)
{
    NodeKhachHang *p;
    for(p=L.Head; p!=NULL; p=p->next)
    {
        if(tma==p->infor.ma)
        {
            return true;
        }

    }
    return false;
}
void TimKiemKhachHangTheoTen(ListKhachHang L)
{
    char tten[30];
    cout<<"\nNhap ten can tim: ";
    gets(tten);
    fflush(stdin);
    NodeKhachHang *p=Get_NodeTenKhachHang(L,tten);
    if(p!=NULL)
    {
        cout<<"\nKhach Hang Da Tim Thay: ";
        TableKhachHang();
        HienKhachHang(p);
    }
    else
    {
        cout<<"\nKhong tim thay khach hang!!!";
    }
}

void SuaDiaChiKhachHang(ListKhachHang &L)
{
    char tdichi[30];
    char tten[30];
    cout<<"\nNhap ten can tim: ";
    gets(tten);
    fflush(stdin);
    NodeKhachHang *p=Get_NodeTenKhachHang(L,tten);
    if(p!=NULL)
    {
        cout<<"\nNhap Moi Dia Chi:";
        gets(tdichi);
        fflush(stdin);
        strcpy(p->infor.diachi,tdichi);
        cout<<"\nKhach Hang Sau Khi Sua: ";
        TableKhachHang();
        HienKhachHang(p);
    }
    else
    {
        cout<<"\nKhong tim thay khach hang!!!";
    }
}

void XoaPhanTuDau(ListKhachHang &L)
{
    NodeKhachHang *p=new NodeKhachHang;
    if(L.Head!=NULL)
    {
        p=L.Head;
        L.Head=L.Head->next;
        delete p;
        if(L.Head==NULL)
            L.Tail=NULL;
    }
}
void XoaPhanTuCuoi(ListKhachHang &L)
{
    for(NodeKhachHang *p=L.Head; p!=NULL; p=p->next)
    {
        if(p->next==L.Tail)
        {
            delete L.Tail;
            p->next=NULL;
            L.Tail=p;
        }
    }
}
void XoaPhieuKhachHangTheoTen(ListKhachHang &L)
{
    NodeKhachHang *ak=new NodeKhachHang;
    char tten[30];
    cout<<"\nNhap Ten Sach de xoa: ";
    gets(tten);
    fflush(stdin);
    int d=0;
    for(NodeKhachHang *p=L.Head; p!=NULL; p=p->next)
    {
        if(strcmp(p->infor.ten,tten)==0)
        {
            d++;
        }
    }
    if(d==0)
    {
        cout<<"\nKhong co Khach Hang Nay!!";
    }
    else
    {
        if(strcmp(L.Head->infor.ten,tten)==0)
        {
            XoaPhanTuDau(L);
            HienListKhachHang(L);
        }
        else if(strcmp(L.Tail->infor.ten,tten)==0)
        {
            XoaPhanTuCuoi(L);
            HienListKhachHang(L);
        }
        else
        {
            for(NodeKhachHang *k=L.Head; k!=NULL; k=k->next)
            {
                ak=k->next;
                if(strcmp(ak->infor.ten,tten)==0)
                {
                    k->next=ak->next;
                    break;
                }
            }
            delete ak;
            HienListKhachHang(L);
        }
    }
}


void LuuFileKH(ListKhachHang L)
{
    FILE *f ;
    f=fopen("KhachHang.dat","wb");
    NodeKhachHang *p=L.Head;
    while(p!=NULL)
    {
        KhachHang *x=&(p->infor);
        fwrite(x,sizeof(KhachHang),1,f);
        p=p->next;
    }
    fclose(f);
    cout<<"\nDa luu file thanh cong";
}

void DocFileKH(ListKhachHang &S)
{
    if(CheckEmpty(S))
    {
        struct KhachHang n;
        FILE *f=fopen("KhachHang.dat","rb");
        while(fread(&n,sizeof(KhachHang),1,f))
        {
            NodeKhachHang *p=Get_NodeKhachHang(n);
            InsertLastKhachHang(S,p);
        }
        fclose(f);
        HienListKhachHang(S);
    }
    else
    {
        ListKhachHang Q;
        KhoiTaoDSKhachHang(Q);
        struct KhachHang n;
        FILE *f=fopen("KhachHang.dat","rb");
        while(fread(&n,sizeof(KhachHang),1,f))
        {
            NodeKhachHang *p=Get_NodeKhachHang(n);
            InsertLastKhachHang(Q,p);
        }
        fclose(f);
        HienListKhachHang(Q);
    }
}
//struct Sachtrong phieu mua

struct SachMua
{
    char ten[30];
    int soluong;
    float dongia;
    float thanhtien;
};
void NhapSachMua(SachMua &x,ListSach S)
{
    NodeSach *p;
    int cou=0;
    do
    {
        cout<<"\nNhap ten Sach: ";
        gets(x.ten);
        fflush(stdin);

        for(p=S.Head; p!=NULL; p=p->next)
        {
            if(strcmp(x.ten,p->infor.ten)==0)
            {
                cou++;
                break;
            }
        }
        if(cou==0)
        {
            cout<<"\nKhong co Sach nay trong cua hang!!";
        }
    }
    while(cou==0);
    x.dongia=p->infor.dongia;
    fflush(stdin);
    cout<<"\nNhap so luong mua: ";
    cin>>x.soluong;
    fflush(stdin);
    x.thanhtien = x.soluong*x.dongia;
    fflush(stdin);
}
float NhapDSSachMua(SachMua ds[],int n,ListSach S)
{
    float tongtien=0;
    for(int i=0; i<n; i++)
    {
        cout<<"San Pham thu "<<i+1;
        NhapSachMua(ds[i],S);
        tongtien +=ds[i].thanhtien;
    }
    return tongtien;
}
void TableSachMua()
{
    cout<<"\n"<<setw(20)<<"Ten Sach"<<setw(20)<<"So Luong"<<setw(20)<<"Don Gia"<<setw(20)<<"Thanh Tien";
}
void HienSachMua(SachMua s)
{
    cout<<"\n"<<setw(20)<<s.ten<<setw(20)<<s.soluong<<setw(20)<<s.dongia<<setw(20)<<s.thanhtien;
}
void HienDSSachMua(SachMua ds[],int n)
{
    cout<<endl<<"\n"<<"\t"<<"DS Sach da mua: ";
    TableSachMua();
    for(int i=0; i<n; i++)
    {
        HienSachMua(ds[i]);
    }
}
//struct Phieu Mua Hang
struct PhieuMua
{
    char maP[50];
    char TGLap[30];
    char tenkh[30];
    int makh;
    SachMua listsm[30];
    int tongmua;
    float tongTien;
};

//tao struct Node Sach
struct NodePM
{
    PhieuMua infor;
    struct NodePM *next;
};
//tao list Sach
struct ListPM
{
    NodePM *Head;
    NodePM *Tail;
};
//Khoi tao danh sach sach
void KhoiTaoDSPM(ListPM &L)
{
    L.Head=NULL;
    L.Tail=NULL;
}
//Khoi tao Node Sach
NodePM *Get_NodePM(PhieuMua x)
{
    NodePM *p=new NodePM;
    if(p==NULL)
    {
        cout<<"Het bo nho de su dung!!!";
        return NULL;
    }
    p->infor=x;
    p->next=NULL; //Mới khai báo NODE nên không liên kết với các NODE khác
    return p;
}
//Chen Node Vao cuoi ds
void InsertLastPM(ListPM &L,NodePM *p)
{
    if(L.Head==NULL)
    {
        L.Head=p;
        L.Tail=L.Head;
    }
    else
    {
        L.Tail->next=p;
        L.Tail=p;
    }
}
bool CheckEmpty(ListPM &L)
{
    if(L.Head==NULL) return 1;
    else return 0;
}
//Nhap sach
void NhapPM(PhieuMua &x,ListSach S,ListKhachHang K)
{
    NodeKhachHang *p;
    cout<<"\nNhap ma: ";
    gets(x.maP);
    fflush(stdin);
    cout<<"\nNhap Thoi Gian Lap: ";
    gets(x.TGLap);
    fflush(stdin);
    do
    {
        cout<<"\nNhap Ten Khach Hang: ";
        gets(x.tenkh);
        p=Get_NodeTenKhachHang(K,x.tenkh);
        fflush(stdin);
        if(p==NULL)
        {
            cout<<"\nKhong co Ten Khach Hang nay!!";
        }
    }
    while(p==NULL);
    x.makh=p->infor.ma;
    int n;
    cout<<"Nhap so luong Cac san Pham: ";
    cin>>n;
    fflush(stdin);
    x.tongTien=NhapDSSachMua(x.listsm,n,S);
    x.tongmua=n;
}
//Nhap dsSach
void NhapDSPM(ListPM &L,ListSach S,ListKhachHang K)
{
    int sl;
    NodePM *p;
    PhieuMua x;
    cout<<"\nNhap So Phieu Mua: ";
    cin>>sl;
    fflush(stdin);
    for(int i=0; i<sl; i++)
    {
        cout<<"PM thu "<<i+1;
        NhapPM(x,S,K);
        p=Get_NodePM(x);
        InsertLastPM(L,p);
    }
}
//hien dssach
void TablePM(NodePM *p)
{
    cout<<endl;
    cout<<endl;
    cout<<"\n"<<setw(20)<<"Ma PM: "<<setw(1)<<p->infor.maP<<setw(15)<<"TG Lap: "<<p->infor.TGLap;
    cout<<"\n"<<setw(20)<<"Ma KH: "<<setw(1)<<p->infor.makh<<setw(17)<<"Ten KH: "<<p->infor.tenkh;
    HienDSSachMua(p->infor.listsm,p->infor.tongmua);
}
void TablePMend(NodePM *p)
{
    cout<<endl<<"\n"<<setw(23)<<"Tong San Pham: "<<p->infor.tongmua<<setw(52)<<"Tong thanh toan: "<<p->infor.tongTien;
}
void HienListPM(ListPM L)
{
    NodePM *p;
    for(p=L.Head; p!=NULL; p=p->next)
    {
        TablePM(p);
        TablePMend(p);
    }
}

void TimKiemPhieuMuatheoTenKhachHang(ListPM L)
{
    char tten[30];
    int dem=0;
    cout<<"\nNhap Ten Khach Hang Can Tim: ";
    gets(tten);
    fflush(stdin);
    cout<<endl<<"\nPhieu mua co Khach Hang "<<tten;
    for(NodePM *p=L.Head; p!=NULL; p=p->next)
    {
        if(strcmp(p->infor.tenkh,tten)==0)
        {
            TablePM(p);
            TablePMend(p);
            dem++;
        }
    }
    if(dem==0)
    {
        cout<<"\nKHong co Phieu mua co khach hang nay";
    }
}
void SapXepPhieuMuaTheoTongThanhToan(ListPM &L)
{
    for(NodePM *i=L.Head; i!=NULL; i=i->next)
    {
        for(NodePM *j=i->next; j!=NULL; j=j->next)
        {
            if(i->infor.tongTien > j->infor.tongTien)
            {
                NodePM *p =new NodePM;
                p->infor=i->infor;
                i->infor=j->infor;
                j->infor=p->infor;
                delete p;
            }
        }
    }
    cout<<"\nPhieu Mua sau khi sap xep: ";
    HienListPM(L);
}
void XoaPhanTuDau(ListPM &L)
{
    NodePM *p=new NodePM;
    if(L.Head!=NULL)
    {
        p=L.Head;
        L.Head=L.Head->next;
        delete p;
        if(L.Head==NULL)
          L.Tail=NULL;
    }
}
void XoaPhanTuCuoi(ListPM &L)
{
    for(NodePM *p=L.Head; p!=NULL; p=p->next)
    {
        if(p->next==L.Tail)
        {
            delete L.Tail;
            p->next=NULL;
            L.Tail=p;
        }
    }
}
void XoaPhieuMuaTheoMa(ListPM &L)
{
    NodePM *ak=new NodePM;
    char tten[30];
    cout<<"\nNhap Ma Phieu Mua de xoa: ";
    gets(tten);
    fflush(stdin);
    int d=0;
    for(NodePM *p=L.Head; p!=NULL; p=p->next)
    {
        if(strcmp(p->infor.maP,tten)==0)
        {
            d++;
        }
    }
    if(d==0)
    {
        cout<<"\nKhong co Phieu Mua Nay!!";
    }
    else
    {
        if(strcmp(L.Head->infor.maP,tten)==0)
        {
            XoaPhanTuDau(L);
            HienListPM(L);
        }
        else if(strcmp(L.Tail->infor.maP,tten)==0)
        {
            XoaPhanTuCuoi(L);
            HienListPM(L);
        }
        else
        {
            for(NodePM *k=L.Head; k!=NULL; k=k->next)
            {
                ak=k->next;
                if(strcmp(ak->infor.maP,tten)==0)
                {
                    k->next=ak->next;
                    break;
                }
            }
            delete ak;
            HienListPM(L);
        }
    }
}

void PhieumuaConhieuTongTienNhat(ListPM L)
{
    NodePM *_max=L.Head;
    for(NodePM *p=L.Head->next; p!=NULL; p=p->next)
    {
        if(_max->infor.tongTien<p->infor.tongTien)
            _max=p;
    }
    cout<<"\nPhieu mua co Tong tien thanh toan nhieu nhat: ";
    TablePM(_max);
    TablePMend(_max);
}
struct NguoiMuaPhieu
{
    char ten[30];
    int sl=0;
};
void CoNhieuPhieuMuaNhat(ListPM L)
{
    int m=0;
    NguoiMuaPhieu ds[10];
    strcpy(ds[0].ten,L.Head->infor.tenkh);
    ds[0].sl++;
    m++;
    for(NodePM *p=L.Head->next; p!=NULL; p=p->next)
    {
        bool co=false;
        for(int i=0; i<m; i++)
        {
            if(strcmp(p->infor.tenkh,ds[i].ten)==0)
            {
                ds[i].sl++;
                co=true;
            }
        }
        if(co!=true)
        {
            strcpy(ds[m].ten,p->infor.tenkh);
            ds[m].sl++;
            m++;
        }
    }
    NguoiMuaPhieu _max = ds[0];
    for(int i=1; i<m; i++)
    {
        if(_max.sl<ds[i].sl)
        {
            _max=ds[i];
        }
    }
    cout<<"\nKhach Hang Co Nhieu Phieu Mua Nhat: "<<_max.ten;
    cout<<"\nSo Luong PM: "<<_max.sl;
}

void PhieuMuaCoTongTienItNhat(ListPM L)
{
    NodePM *_min=L.Head;
    for(NodePM *p=L.Head; p!=NULL; p=p->next)
    {
        if(_min->infor.tongTien > p->infor.tongTien)
        {
            _min=p;
        }
    }
    cout<<"\nPhieu Mua Co Tong Tien It Nhat:";
    TablePM(_min);
    TablePMend(_min);
}
void LuuFilePM(ListPM L)
{
    if(L.Head==NULL)
    {
        cout<<"\nKhong co du lieu de luu";
    }
    else
    {
        FILE *f ;
        f=fopen("PhieuMua.dat","wb");
        NodePM *p=L.Head;
        while(p!=NULL)
        {
            PhieuMua *x=&(p->infor);
            fwrite(x,sizeof(PhieuMua),1,f);
            p=p->next;
        }
        fclose(f);
        cout<<"\nDa luu file thanh cong";
    }
}
void DocFilePM(ListPM &S)
{
    if(CheckEmpty(S))
    {
        struct PhieuMua n;
        FILE *f=fopen("PhieuMua.dat","rb");
        while(fread(&n,sizeof(PhieuMua),1,f))
        {
            NodePM *p=Get_NodePM(n);
            InsertLastPM(S,p);
        }
        fclose(f);
        HienListPM(S);
    }
    else
    {
        ListPM Q;
        KhoiTaoDSPM(Q);
        struct PhieuMua n;
        FILE *f=fopen("PhieuMua.dat","rb");
        while(fread(&n,sizeof(PhieuMua),1,f))
        {
            NodePM *p=Get_NodePM(n);
            InsertLastPM(Q,p);
        }
        fclose(f);
        HienListPM(Q);
    }
}


//Declare MENU
void MenuSach(ListSach &S,ListKhachHang &K,ListPM &P);
void MenuPM(ListSach &S,ListKhachHang &K,ListPM &P);
void MenuChinh(ListSach &S,ListKhachHang &K,ListPM &P);

//MENU
//MenuSach
void MenuSach(ListSach &S,ListKhachHang &K,ListPM &P)
{
    int chon;
    do
    {
        cout<<"\n===========MENU-SACH===========";
        cout<<"\n1.Nhap DS Sach";
        cout<<"\n2.Hien DS Sach";
        cout<<"\n3.Sap Xep Sach Theo Don Gia";
        cout<<"\n4.Tim Kiem Sach Theo Ten";
        cout<<"\n5.Sua Don Gia Sach Theo Ten";
        cout<<"\n6.Xoa Sach Theo Ten";
        cout<<"\n7.Ghi File";
        cout<<"\n8.Doc File";
        cout<<"\n0.Thoat ra MENU CHINH";
        cout<<"\nChon: ";
        cin>>chon;
        fflush(stdin);
        switch(chon)
        {
        case 1:
            NhapDSSach(S);
            cout<<endl;
            break;
        case 2:
            HienListSach(S);
            cout<<endl;
            break;
        case 3:
            SapXepSachTheoDonGia(S);
            cout<<endl;
            break;
        case 4:
            TimKiemSachTheoTen(S);
            cout<<endl;
            break;
        case 5:
            SuaGiaSachTheoTen(S);
            cout<<endl;
            break;
        case 6:
            XoaPhieuSachTheoTen(S);
            cout<<endl;
            break;
        case 7:
            LuuFileSach(S);
            cout<<endl;
            break;
        case 8:
            DocFileSach(S);
            cout<<endl;
            break;
        case 0:
            cout<<"\nThoat ra Menu Chinh";
            MenuChinh(S,K,P);
            break;
        default:
            cout<<"\nKhong phai chuc nang!!";
            break;
        }

    }
    while(chon!=0);
}
//MENUKH
void MenuKH(ListSach &S,ListKhachHang &K,ListPM &P)
{
    int chon;
    do
    {
        cout<<"\n===========Menu-KHACHHANG===========";
        cout<<"\n1.Nhap DS Khach Hang";
        cout<<"\n2.Hien DS Khach Hang";
        cout<<"\n3.Tim Kiem Ten Khach Hang";
        cout<<"\n4.Sua Dia Chi Khach Hang Theo Ten";
        cout<<"\n5.Xoa Khach Hang Theo Ten";
        cout<<"\n6.Ghi File";
        cout<<"\n7.Doc File";
        cout<<"\n0.Thoat ra MENU CHINH";
        cout<<"\nChon: ";
        cin>>chon;
        fflush(stdin);
        switch(chon)
        {
        case 1:
            NhapDSKhachHang(K);
            cout<<endl;
            break;
        case 2:
            HienListKhachHang(K);
            cout<<endl;
            break;
        case 3:
            TimKiemKhachHangTheoTen(K);
            cout<<endl;
            break;
        case 4:
            SuaDiaChiKhachHang(K);
            cout<<endl;
            break;
         case 5:
            XoaPhieuKhachHangTheoTen(K);
            cout<<endl;
            break;
        case 6:
            LuuFileKH(K);
            cout<<endl;
            break;
        case 7:
            DocFileKH(K);
            cout<<endl;
            break;
        case 0:
            cout<<"\nThoat ra Menu Chinh";
            MenuChinh(S,K,P);
            break;
        default:
            cout<<"\nKhong phai chuc nang!!";
            break;
        }

    }
    while(chon!=0);
}
//MENUPM
void MenuPM(ListSach &S,ListKhachHang &K,ListPM &P)
{
    int chon;
    do
    {
        cout<<"\n===========MENU-PHIEUMUA===========";
        cout<<"\n1.Nhap DS Phieu Mua";
        cout<<"\n2.Hien DS Phieu Mua";
        cout<<"\n3.Tim Kiem Phieu Mua Theo Ten Khach Hang";
        cout<<"\n4.Sap Xep Phieu Mua Theo Tong Thanh Tien";
        cout<<"\n5.Xoa Phieu Mua theo Ma";
        cout<<"\n6.Khach Hang Co Nhieu Phieu Mua Nhat";
        cout<<"\n7.Phieu Mua Co Tong Tien It Nhat";
        cout<<"\n8.Ghi File";
        cout<<"\n9.Doc File";
        cout<<"\n0.Thoat ra MENU CHINH";
        cout<<"\nChon: ";
        cin>>chon;
        fflush(stdin);
        switch(chon)
        {
        case 1:
            NhapDSPM(P,S,K);
            cout<<endl;
            break;
        case 2:
            HienListPM(P);
            cout<<endl;
            break;
        case 3:
            TimKiemPhieuMuatheoTenKhachHang(P);
            cout<<endl;
            break;
        case 4:
            SapXepPhieuMuaTheoTongThanhToan(P);
            cout<<endl;
            break;
        case 5:
            XoaPhieuMuaTheoMa(P);
            cout<<endl;
            break;
        case 6:
            CoNhieuPhieuMuaNhat(P);
            cout<<endl;
            break;
        case 7:
            PhieuMuaCoTongTienItNhat(P);
            cout<<endl;
            break;
        case 8:
            LuuFilePM(P);
            cout<<endl;
            break;
        case 9:
            DocFilePM(P);
            cout<<endl;
            break;
        case 0:
            cout<<"\nThoat ra Menu Chinh";
            MenuChinh(S,K,P);
            break;
        default:
            cout<<"\nKhong phai chuc nang!!";
            break;
        }

    }
    while(chon!=0);
}
void MenuChinh(ListSach &S,ListKhachHang &K,ListPM &P)
{
    int chon;
    do
    {
        cout<<"\n\n======QUAN LY BAN SACH TAI CUA HANG SACH=====";
        cout<<"\n1. Quan ly Sach";
        cout<<"\n2. Quan ly Khach Hang";
        cout<<"\n3. Quan ly Phieu Mua Sach";
        cout<<"\n0. Thoat";
        cout<<"\nChon: ";
        cin>>chon;
        fflush(stdin);
        switch(chon)
        {
        case 1:
            MenuSach(S,K,P);
            break;
        case 2:
            MenuKH(S,K,P);
            break;
        case 3:
            MenuPM(S,K,P);
            break;
        case 0:
            cout<<"\nThoat Chuong Trinh!!";
            exit(0);
        default :
            cout<<"\nKhong dung chuc nang, Nhap lai: ";
        }
    }
    while(chon!=0);

}
int main()
{
    ListSach lists;
    ListKhachHang Listkh;
    ListPM  listpm;
    KhoiTaoDSSach(lists);
    KhoiTaoDSKhachHang(Listkh);
    KhoiTaoDSPM(listpm);
//   NhapDSKhachHang(Listkh);
//    Duyettucuoi(Listkh);
//    SapXepKhachHangTheoMa(Listkh);
//    Duyettucuoi(Listkh);
//    TimKiemKhachHangTheoMa(Listkh);
//
    MenuChinh(lists,Listkh,listpm);
//    KhoiTaoDSPM(listpm);
//    NhapDSPM(listpm);
//    HienListPM(listpm);
}
