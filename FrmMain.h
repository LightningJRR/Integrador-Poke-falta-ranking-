#pragma once
#include "Controller.h"
#include <fstream>
//#include "File.h"
namespace ejerciciointegradorpoke {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	public:
		FrmMain(void)
		{
			//
			//TODO: agregar código de constructor aquí
			//
			srand(time(NULL));
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			pikachu = gcnew Bitmap("pikachu.png");
			pokeball = gcnew Bitmap("pokeball.png");
			superball = gcnew Bitmap("superball.png");
			ultraball = gcnew Bitmap("ultraball.png");
			masterball = gcnew Bitmap("masterball.png");
			fondo = gcnew Bitmap("fondo.png");

			//file 
			//file = new File();
			//file->readData(pikachu,pokeball);

			controller = new Controller(pikachu, pokeball);
			myTime = controller->gettiempo();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ pikachu;
		Bitmap^ pokeball;
		Bitmap^ superball;
		Bitmap^ ultraball;
		Bitmap^ masterball;
		Bitmap^ fondo;
		Controller* controller;


		//TIME
		int myTime;

		//FILE
		//File* file;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Label^ labelHP;

	private: System::Windows::Forms::Label^ labelT;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ timerTime;
	private: System::Windows::Forms::Label^ contP;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ contMB;
	private: System::Windows::Forms::Label^ contUB;
	private: System::Windows::Forms::Label^ contSB;
	private: System::Windows::Forms::Label^ contPoke;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->contMB = (gcnew System::Windows::Forms::Label());
			   this->contUB = (gcnew System::Windows::Forms::Label());
			   this->contSB = (gcnew System::Windows::Forms::Label());
			   this->contPoke = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->contP = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->labelT = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->labelHP = (gcnew System::Windows::Forms::Label());
			   this->timerTime = (gcnew System::Windows::Forms::Timer(this->components));
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &FrmMain::timer1_Tick);
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->contMB);
			   this->panel1->Controls->Add(this->contUB);
			   this->panel1->Controls->Add(this->contSB);
			   this->panel1->Controls->Add(this->contPoke);
			   this->panel1->Controls->Add(this->label6);
			   this->panel1->Controls->Add(this->label5);
			   this->panel1->Controls->Add(this->label4);
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Controls->Add(this->contP);
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Controls->Add(this->labelT);
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Controls->Add(this->labelHP);
			   this->panel1->Location = System::Drawing::Point(1, 1);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(653, 482);
			   this->panel1->TabIndex = 0;
			   // 
			   // contMB
			   // 
			   this->contMB->AutoSize = true;
			   this->contMB->Location = System::Drawing::Point(365, 49);
			   this->contMB->Name = L"contMB";
			   this->contMB->Size = System::Drawing::Size(13, 13);
			   this->contMB->TabIndex = 13;
			   this->contMB->Text = L"0";
			   // 
			   // contUB
			   // 
			   this->contUB->AutoSize = true;
			   this->contUB->Location = System::Drawing::Point(307, 49);
			   this->contUB->Name = L"contUB";
			   this->contUB->Size = System::Drawing::Size(13, 13);
			   this->contUB->TabIndex = 12;
			   this->contUB->Text = L"0";
			   // 
			   // contSB
			   // 
			   this->contSB->AutoSize = true;
			   this->contSB->Location = System::Drawing::Point(214, 49);
			   this->contSB->Name = L"contSB";
			   this->contSB->Size = System::Drawing::Size(13, 13);
			   this->contSB->TabIndex = 11;
			   this->contSB->Text = L"0";
			   // 
			   // contPoke
			   // 
			   this->contPoke->AutoSize = true;
			   this->contPoke->Location = System::Drawing::Point(131, 49);
			   this->contPoke->Name = L"contPoke";
			   this->contPoke->Size = System::Drawing::Size(13, 13);
			   this->contPoke->TabIndex = 10;
			   this->contPoke->Text = L"0";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(365, 12);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(56, 13);
			   this->label6->TabIndex = 9;
			   this->label6->Text = L"MasterBall";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(294, 12);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(46, 13);
			   this->label5->TabIndex = 8;
			   this->label5->Text = L"UltraBall";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(211, 12);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(57, 13);
			   this->label4->TabIndex = 7;
			   this->label4->Text = L"SuperBalls";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(128, 12);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(53, 13);
			   this->label3->TabIndex = 6;
			   this->label3->Text = L"Pokeballs";
			   // 
			   // contP
			   // 
			   this->contP->AutoSize = true;
			   this->contP->Location = System::Drawing::Point(59, 50);
			   this->contP->Name = L"contP";
			   this->contP->Size = System::Drawing::Size(13, 13);
			   this->contP->TabIndex = 5;
			   this->contP->Text = L"0";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(12, 50);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(40, 13);
			   this->label1->TabIndex = 4;
			   this->label1->Text = L"Puntos";
			   // 
			   // labelT
			   // 
			   this->labelT->AutoSize = true;
			   this->labelT->Location = System::Drawing::Point(47, 12);
			   this->labelT->Name = L"labelT";
			   this->labelT->Size = System::Drawing::Size(13, 13);
			   this->labelT->TabIndex = 3;
			   this->labelT->Text = L"0";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(11, 12);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(30, 13);
			   this->label2->TabIndex = 2;
			   this->label2->Text = L"Time";
			   // 
			   // labelHP
			   // 
			   this->labelHP->AutoSize = true;
			   this->labelHP->Location = System::Drawing::Point(52, 12);
			   this->labelHP->Name = L"labelHP";
			   this->labelHP->Size = System::Drawing::Size(0, 13);
			   this->labelHP->TabIndex = 1;
			   // 
			   // timerTime
			   // 
			   this->timerTime->Enabled = true;
			   this->timerTime->Interval = 1000;
			   this->timerTime->Tick += gcnew System::EventHandler(this, &FrmMain::timerTime_Tick);
			   // 
			   // FrmMain
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(653, 486);
			   this->Controls->Add(this->panel1);
			   this->Name = L"FrmMain";
			   this->Text = L"FrmMain";
			   this->Load += gcnew System::EventHandler(this, &FrmMain::FrmMain_Load);
			   //this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			   this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FrmMain::FrmMain_KeyPress);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);
		//colision
		controller->colision(g, pikachu);
		controller->colisionFINAL();
		//mover
		controller->moverEverything(g);

		/*int x, y;
		int hp;
		int myTime;
		x = controller->getPika()->getX();
		y = controller->getPika()->getY();
		hp = controller->getPika()->gethp();
		myTime = controller->gettiempo();*/

		//if (fileWrite.is_open()) {
		//	fileWrite << controller->getPika()->getX() << endl;
		//	fileWrite << controller->getPika()->getY() << endl;
		//	fileWrite << controller->getPika()->gethp() << endl;
		//	fileWrite << controller->gettiempo() << endl;
		//	fileWrite.close();
		//}

		//guardar partida


		//dibujar
		labelT->Text = Convert::ToString(myTime);
		contP->Text = Convert::ToString(controller->getPuntosAcumulados());
		contPoke->Text = Convert::ToString(controller->getCantP());
		contSB->Text = Convert::ToString(controller->getCantS());
		contUB->Text = Convert::ToString(controller->getCantU());
		contMB->Text = Convert::ToString(controller->getCantM());
		buffer->Graphics->DrawImage(fondo, 0, 0, panel1->Width, panel1->Height);
		controller->drawEverything(buffer->Graphics, pikachu, pokeball, superball, ultraball, masterball);
		if (myTime == 0) {
			timer1->Stop();
			MessageBox::Show("Se termino el juego!!!");
			//remove("configuration.txt");
			this->Close();
		}
		else
		{
			buffer->Render(g);
		}

	}
	private: System::Void timerTime_Tick(System::Object^ sender, System::EventArgs^ e) {
		myTime--;
	}
	private: System::Void FrmMain_Load(System::Object^ sender, System::EventArgs^ e) {
		//ofstream fileWrite;
		//fileWrite.open("configuration.txt"); //Creates the new txt
		//fileWrite << controller->getPika()->getX() << endl;
		//fileWrite << controller->getPika()->getY() << endl;
		//fileWrite << controller->getPika()->gethp() << endl;
		//fileWrite << controller->gettiempo() << endl;
		//fileWrite.close();
	}

	private: void guardarpartida() {
		ofstream file_partida;
		file_partida.open("partida.txt", ios::out);
		
		int tiempo,pikachu,puntos, pokeball, superball, ultraball, masterball;

		tiempo = myTime;
		pikachu = controller->getCantPika().size();
		puntos = controller->getPuntosAcumulados();
		pokeball = controller->getCantballs().size();
		superball = controller->getCantSballs().size();
		ultraball = controller->getCantUballs().size();
		masterball = controller->getCantMballs().size();
		
		if (file_partida.is_open()) {
			file_partida << tiempo << endl;
			file_partida << pikachu << endl;
			for (int i = 0;i < pikachu;i++) {
				file_partida << controller->getCantPika()[i]->getX() << endl;
				file_partida << controller->getCantPika()[i]->getY() << endl;
				file_partida << controller->getCantPika()[i]->getIDX() << endl;
				file_partida << controller->getCantPika()[i]->getIDY() << endl;
				file_partida << controller->getCantPika()[i]->getdX() << endl;
				file_partida << controller->getCantPika()[i]->getdY() << endl;
			}
			file_partida << puntos << endl;
			file_partida << pokeball << endl;
			for (int i = 0;i < pokeball;i++) {
				file_partida << controller->getCantballs()[i]->getX() << endl;
				file_partida << controller->getCantballs()[i]->getY() << endl;
				file_partida << controller->getCantballs()[i]->getIDX() << endl;
				file_partida << controller->getCantballs()[i]->getIDY() << endl;
				file_partida << controller->getCantballs()[i]->getdX() << endl;
				file_partida << controller->getCantballs()[i]->getdY() << endl;
			}
			file_partida << superball << endl;
			for (int i = 0;i < superball;i++) {
				file_partida << controller->getCantSballs()[i]->getX() << endl;
				file_partida << controller->getCantSballs()[i]->getY() << endl;
				file_partida << controller->getCantSballs()[i]->getIDX() << endl;
				file_partida << controller->getCantSballs()[i]->getIDY() << endl;
				file_partida << controller->getCantSballs()[i]->getdX() << endl;
				file_partida << controller->getCantSballs()[i]->getdY() << endl;
			}
			file_partida << ultraball << endl;
			for (int i = 0;i < ultraball;i++) {
				file_partida << controller->getCantUballs()[i]->getX() << endl;
				file_partida << controller->getCantUballs()[i]->getY() << endl;
				file_partida << controller->getCantUballs()[i]->getIDX() << endl;
				file_partida << controller->getCantUballs()[i]->getIDY() << endl;
				file_partida << controller->getCantUballs()[i]->getdX() << endl;
				file_partida << controller->getCantUballs()[i]->getdY() << endl;
			}
			file_partida << masterball << endl;
			for (int i = 0;i < masterball;i++) {
				file_partida << controller->getCantMballs()[i]->getX() << endl;
				file_partida << controller->getCantMballs()[i]->getY() << endl;
				file_partida << controller->getCantMballs()[i]->getIDX() << endl;
				file_partida << controller->getCantMballs()[i]->getIDY() << endl;
				file_partida << controller->getCantMballs()[i]->getdX() << endl;
				file_partida << controller->getCantMballs()[i]->getdY() << endl;
			}
			file_partida.close();
			MessageBox::Show("Se guardo su partida de pokemon :D");
		}
	}
	private: void cargarpartida() {
		//no funciona del todo bien profe :c
		ifstream file_partida;
		file_partida.open("partida.txt", ios::out);
		int tiempo, pikachu, puntos, pokeball, superball, ultraball, masterball;
		int x, y, idx, idy, dx, dy;

		tiempo = myTime;
		pikachu = controller->getCantPika().size();
		puntos = controller->getPuntosAcumulados();
		pokeball = controller->getCantballs().size();
		superball = controller->getCantSballs().size();
		ultraball = controller->getCantUballs().size();
		masterball = controller->getCantMballs().size();

		if (file_partida.is_open()) {
			file_partida >> tiempo;
			file_partida >> pikachu;
			for (int i = 0;i < pikachu;i++) {
				file_partida >> x;
				file_partida >> y;
				file_partida >> idx;
				file_partida >> idy;
				file_partida >> dx;
				file_partida >> dy;
				Pikachu* pikatemp = new Pikachu(x, y, idx, idy, dx, dy);
				controller->agregarPikaTemp(pikatemp);
			}
			file_partida >> puntos;
			file_partida >> pokeball;
			for (int i = 0;i < pokeball;i++) {
				file_partida >> x;
				file_partida >> y;
				file_partida >> idx;
				file_partida >> idy;
				file_partida >> dx;
				file_partida >> dy;
				Pokeball* balltemp = new Pokeball(x, y, idx, idy, dx, dy);
				controller->agregarPokeTemp(balltemp);
			}
			file_partida >> superball;
			for (int i = 0;i < superball;i++) {
				file_partida >> x;
				file_partida >> y;
				file_partida >> idx;
				file_partida >> idy;
				file_partida >> dx;
				file_partida >> dy;
				SuperBall* suptemp = new SuperBall(x, y, idx, idy, dx, dy);
				controller->agregarSuperTemp(suptemp);
			}
			file_partida >> ultraball;
			for (int i = 0;i < ultraball;i++) {
				file_partida >> x;
				file_partida >> y;
				file_partida >> idx;
				file_partida >> idy;
				file_partida >> dx;
				file_partida >> dy;
				UltraBall* ultemp = new UltraBall(x, y, idx, idy, dx, dy);
				controller->agregarUltraTemp(ultemp);
			}
			file_partida >> masterball;
			for (int i = 0;i < masterball;i++) {
				file_partida >> x;
				file_partida >> y;
				file_partida >> idx;
				file_partida >> idy;
				file_partida >> dx;
				file_partida >> dy;
				MasterBall* mastemp = new MasterBall(x, y, idx, idy, dx, dy);
				controller->agregarMasterTemp(mastemp);
			}
			controller->setArrPika(controller->getCantPika());
			controller->setArrBalls(controller->getCantballs());
			controller->setArrSB(controller->getCantSballs());
			controller->setArrUB(controller->getCantUballs());
			controller->setArrMB(controller->getCantMballs());
			file_partida.close();
			MessageBox::Show("Se cargo su partida de pokemon :D");
		}
	
	}

	private: System::Void FrmMain_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		int random = rand() % 4;
		switch (e->KeyChar)
		{
		case 'P': timer1->Stop();
			timerTime->Stop(); 
			break;
		case 'O': timer1->Start();
			timerTime->Start(); 
			break;
		case 'S': guardarpartida();
			break;
		case 'L': cargarpartida();
			break;
		case 'B': 
			switch (random){
			case 0:
				if (controller->getCantP() >= 1) {
					controller->agregarPokeball(pokeball);
					controller->reducirP();
				} break;
			case 1: if (controller->getCantS() >= 1) {
				controller->agregarSuperBall(superball);
				controller->reducirS();
			} break;
			case 2: if (controller->getCantU() >= 1) {
				controller->agregarUltraBall(ultraball);
				controller->reducirU();
			}break;
			case 3: if (controller->getCantM() >= 1) {
				controller->agregarMasterBall(masterball);
				controller->reducirM();
			}break;
			}
		}
	}
	};
}
