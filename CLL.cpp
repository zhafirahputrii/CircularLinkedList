//ZhafirahNurShadrinaPutri
//G1A021028
//CLL
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
	struct node *prev;
	struct node *next;
	int data;
};
struct node *head;

void addFirst(){
	struct node *ptr,*temp;
	int item;
	ptr= (struct node *)malloc(sizeof(struct node));
	if (ptr==NULL){
		cout<<"\nList Kosong"<<endl;
	}else{
		cout<<"\nMasukkan Nilai :"<<endl;
		cin>>item;
		ptr->data=item;
		if(head==NULL){
			head=ptr;
			ptr->next=head;
			ptr->prev=head;
		}else{
			temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
			head->prev=ptr;
			ptr->next=head;
			head=ptr;
		}
		cout<<"Nilai Telah Ditambahkan"<<endl;
	}
}
void addLast(){
	struct node *ptr,*temp;
	int item;
	ptr= (struct node *)malloc(sizeof(struct node));
	if (ptr==NULL){
		cout<<"\nList Kosong"<<endl;
	}else{
		cout<<"\nMasukkan Nilai :"<<endl;
		cin>>item;
		ptr->data=item;
		if(head==NULL){
			head=ptr;
			ptr->next=head;
			ptr->prev=head;
		}else{
			temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
			head->prev=ptr;
			ptr->next=head;
		}
		cout<<"Nilai Telah Ditambahkan"<<endl;
	}
}
void deleteFirst(){
	struct node*temp;
	if(head==NULL){
		cout<<"\nList Kosong"<<endl;
	}else if(head->next==head){
		head=NULL;
		free(head);
		cout<<"Nilai Telah Dihapus"<<endl;
	}else{
		temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=head->next;
		head->next->prev=temp;
		free(head);
		head=temp->next;
	}
}
void deleteLast(){
	struct node*ptr;
	if(head==NULL){
		cout<<"\nList Kosong"<<endl;
	}else if(head->next==head){
		head=NULL;
		free(head);
		cout<<"\nNilai Telah Dihapus"<<endl;
	}else{
		ptr=head;
		if(ptr->next!=head)
		{
			ptr=ptr->next;
		}
		ptr->prev->next=head;
		head->prev=ptr->prev;
		free(ptr);
		cout<<"\nNilai Telah Dihapus"<<endl;
	}
}
void tampil(){
	struct node *ptr;
	ptr=head;
	if(head==NULL){
		cout<<"\nList Kosong"<<endl;
	}else{
		cout<<"\nDisplay :"<<endl;
		while(ptr->next!=head){
			cout<< ptr-> data<< (" ") ;
			ptr=ptr->next;
		}		cout<< ptr-> data <<endl;
	}
}

void addFirst();
void addLast();
void deleteFirst();
void deleteLast();
void tampil();
int main(){


	int pilihan = 0;
	while (pilihan!=6)
	{
		cout<<"Circular Linked List"<<endl;
		cout<<"==================================="<<endl;
		cout<<"1. Add First"<<endl;
		cout<<"2. Add Last"<<endl;
		cout<<"3. Delete First"<<endl;
		cout<<"4. Delete Last"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Masukkan Pilihan Anda :"<<endl;
		cin>>pilihan;
		
		switch(pilihan){
			case 1:
				addFirst();
				break;
			case 2:
				addLast();
				break;
			case 3:
				deleteFirst();
				break;
			case 4:
				deleteLast();
				break;
			case 5:
				tampil();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"Pilihan yang Anda Masukkan Salah";
		}
	}
}