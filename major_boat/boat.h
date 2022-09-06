#pragma once
#include<iostream>
#include"opencv2\opencv.hpp"
#include<cmath>
#include<stdio.h>

#define PI                      3.141592654
#define EARTH_RADIUS            6378.137       //earth's radius

namespace major_boat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace cv;
	using namespace System::Threading;


	double get_distance(double lat1, double lng1, double lat2, double lng2) {
		double radlat1 = lat1 * PI / 180.0;   
		double radlat2 = lat2 * PI / 180.0;   
		double a = radlat1 - radlat2;// difference of latitude arc
		double b = lng1 * PI / 180.0 - lng2* PI / 180.0;  //differenve of longitude arc
		double dst = 2 * asin((sqrt(pow(sin(a / 2), 2) + cos(radlat1) * cos(radlat2) * pow(sin(b / 2), 2))));
		dst = dst * EARTH_RADIUS;
		dst = round(dst * 10000) / 10000;
		return dst;
	}

	int get_angle(double lat1, double lng1, double lat2, double lng2) { //north and east are positive
		double x = lat1 - lat2;// difference of latitude
		double y = lng1 - lng2;// differenve of longitude
		int angle = -1;
		if (y == 0 && x < 0) { 
			angle = 0; }
		else if (y == 0 && x > 0) { 
			angle = 180; }
		else if (x == 0 && y < 0) { 
			angle = 90; }
		else if (x == 0 && y > 0) { 
			angle = 270; }
		else if (angle == -1) {
			double dislat = get_distance(lat1, lng2, lat2, lng2);
			double dislng = get_distance(lat2, lng1, lat2, lng2);
			if (x > 0 && y > 0) {
				angle = atan2(dislat, dislng) / PI * 180 + 180;
			}
			else if (x < 0 && y > 0) {
				angle = atan2(dislat, dislng) / PI * 180 + 270;
			}
			else if (x > 0 &&y <0) {
				angle = atan2(dislat, dislng) / PI * 180 + 90;
			}
			else if (x < 0 && y < 0) {
				angle = atan2(dislat, dislng) / PI * 180;
			}			
		}
		return angle;
	}

	inline int pos(string GPS)
	{//GPS資料分析
		int position = GPS.find(',');
		return position;
	}

	/// <summary>
	/// boat 的摘要
	/// </summary>
	public ref class boat : public System::Windows::Forms::Form
	{
	public:
		boat(void)
		{
			InitializeComponent();
			
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~boat()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	protected:
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  Distance;
	private: System::Windows::Forms::Label^  Focus;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  yposition;
	private: System::Windows::Forms::Label^  xposition;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Label^  UTC_date;
	private: System::Windows::Forms::Label^  Direction;
	private: System::Windows::Forms::Label^  Speed;
	private: System::Windows::Forms::Label^  WEhemisphere;
	private: System::Windows::Forms::Label^  Longitude;
	private: System::Windows::Forms::Label^  SNhemisphere;
	private: System::Windows::Forms::Label^  Latitute;
	private: System::Windows::Forms::Label^  Status;
	private: System::Windows::Forms::Label^  UTC_time;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::ComboBox^  comboBox2;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label1;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::IO::Ports::SerialPort^  GPSPort;
	private: System::Windows::Forms::Timer^  timer1;

	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  posShort_distance;
	private: System::Windows::Forms::Button^  posC;
	private: System::Windows::Forms::Button^  posB;
	private: System::Windows::Forms::Button^  posA;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::HScrollBar^  hScrollBar3;
	private: System::Windows::Forms::HScrollBar^  hScrollBar2;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::PictureBox^  pictureBox4;




	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(boat::typeid));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar3 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar2 = (gcnew System::Windows::Forms::HScrollBar());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->Distance = (gcnew System::Windows::Forms::Label());
			this->Focus = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->yposition = (gcnew System::Windows::Forms::Label());
			this->xposition = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->posShort_distance = (gcnew System::Windows::Forms::Button());
			this->posC = (gcnew System::Windows::Forms::Button());
			this->posB = (gcnew System::Windows::Forms::Button());
			this->posA = (gcnew System::Windows::Forms::Button());
			this->UTC_date = (gcnew System::Windows::Forms::Label());
			this->Direction = (gcnew System::Windows::Forms::Label());
			this->Speed = (gcnew System::Windows::Forms::Label());
			this->WEhemisphere = (gcnew System::Windows::Forms::Label());
			this->Longitude = (gcnew System::Windows::Forms::Label());
			this->SNhemisphere = (gcnew System::Windows::Forms::Label());
			this->Latitute = (gcnew System::Windows::Forms::Label());
			this->Status = (gcnew System::Windows::Forms::Label());
			this->UTC_time = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->GPSPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(55, 36);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 23);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &boat::comboBox1_SelectedIndexChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(4, 86);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1211, 620);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label25);
			this->tabPage1->Controls->Add(this->label24);
			this->tabPage1->Controls->Add(this->label23);
			this->tabPage1->Controls->Add(this->label22);
			this->tabPage1->Controls->Add(this->label21);
			this->tabPage1->Controls->Add(this->hScrollBar3);
			this->tabPage1->Controls->Add(this->hScrollBar2);
			this->tabPage1->Controls->Add(this->label20);
			this->tabPage1->Controls->Add(this->label19);
			this->tabPage1->Controls->Add(this->label18);
			this->tabPage1->Controls->Add(this->hScrollBar1);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->Distance);
			this->tabPage1->Controls->Add(this->Focus);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->yposition);
			this->tabPage1->Controls->Add(this->xposition);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->button9);
			this->tabPage1->Controls->Add(this->button8);
			this->tabPage1->Controls->Add(this->button7);
			this->tabPage1->Controls->Add(this->button6);
			this->tabPage1->Controls->Add(this->pictureBox2);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1203, 591);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Vision";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label25->Location = System::Drawing::Point(742, 230);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(93, 17);
			this->label25->TabIndex = 33;
			this->label25->Text = L"目前狀態：";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label24->Location = System::Drawing::Point(899, 230);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(25, 17);
			this->label24->TabIndex = 32;
			this->label24->Text = L"無";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(55, 120);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(32, 15);
			this->label23->TabIndex = 31;
			this->label23->Text = L"V：";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(55, 80);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(30, 15);
			this->label22->TabIndex = 30;
			this->label22->Text = L"S：";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(55, 40);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(32, 15);
			this->label21->TabIndex = 29;
			this->label21->Text = L"H：";
			// 
			// hScrollBar3
			// 
			this->hScrollBar3->Location = System::Drawing::Point(110, 120);
			this->hScrollBar3->Maximum = 264;
			this->hScrollBar3->Name = L"hScrollBar3";
			this->hScrollBar3->Size = System::Drawing::Size(183, 21);
			this->hScrollBar3->TabIndex = 28;
			// 
			// hScrollBar2
			// 
			this->hScrollBar2->Location = System::Drawing::Point(110, 80);
			this->hScrollBar2->Maximum = 264;
			this->hScrollBar2->Name = L"hScrollBar2";
			this->hScrollBar2->Size = System::Drawing::Size(183, 21);
			this->hScrollBar2->TabIndex = 27;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label20->Location = System::Drawing::Point(320, 120);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(16, 17);
			this->label20->TabIndex = 26;
			this->label20->Text = L"0";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label19->Location = System::Drawing::Point(320, 80);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(16, 17);
			this->label19->TabIndex = 25;
			this->label19->Text = L"0";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label18->Location = System::Drawing::Point(320, 40);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(16, 17);
			this->label18->TabIndex = 24;
			this->label18->Text = L"0";
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(110, 40);
			this->hScrollBar1->Maximum = 189;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(183, 21);
			this->hScrollBar1->TabIndex = 23;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label17->Location = System::Drawing::Point(129, 547);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(16, 17);
			this->label17->TabIndex = 22;
			this->label17->Text = L"0";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label16->Location = System::Drawing::Point(55, 547);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(39, 17);
			this->label16->TabIndex = 21;
			this->label16->Text = L"FPS:";
			// 
			// Distance
			// 
			this->Distance->AutoSize = true;
			this->Distance->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->Distance->Location = System::Drawing::Point(899, 470);
			this->Distance->Name = L"Distance";
			this->Distance->Size = System::Drawing::Size(16, 17);
			this->Distance->TabIndex = 20;
			this->Distance->Text = L"0";
			// 
			// Focus
			// 
			this->Focus->AutoSize = true;
			this->Focus->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->Focus->Location = System::Drawing::Point(899, 530);
			this->Focus->Name = L"Focus";
			this->Focus->Size = System::Drawing::Size(16, 17);
			this->Focus->TabIndex = 19;
			this->Focus->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label6->Location = System::Drawing::Point(739, 470);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(71, 17);
			this->label6->TabIndex = 18;
			this->label6->Text = L"距離(cm)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label5->Location = System::Drawing::Point(739, 530);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 17);
			this->label5->TabIndex = 17;
			this->label5->Text = L"焦距";
			// 
			// yposition
			// 
			this->yposition->AutoSize = true;
			this->yposition->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->yposition->Location = System::Drawing::Point(899, 410);
			this->yposition->Name = L"yposition";
			this->yposition->Size = System::Drawing::Size(16, 17);
			this->yposition->TabIndex = 16;
			this->yposition->Text = L"0";
			// 
			// xposition
			// 
			this->xposition->AutoSize = true;
			this->xposition->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->xposition->Location = System::Drawing::Point(899, 350);
			this->xposition->Name = L"xposition";
			this->xposition->Size = System::Drawing::Size(16, 17);
			this->xposition->TabIndex = 15;
			this->xposition->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label4->Location = System::Drawing::Point(739, 410);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 17);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Y：";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label3->Location = System::Drawing::Point(739, 350);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 17);
			this->label3->TabIndex = 13;
			this->label3->Text = L"X：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label2->Location = System::Drawing::Point(739, 290);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 17);
			this->label2->TabIndex = 8;
			this->label2->Text = L"重心";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(902, 161);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 12;
			this->button9->Text = L"右轉";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &boat::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(742, 161);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 11;
			this->button8->Text = L"左轉";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &boat::button8_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(902, 87);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 10;
			this->button7->Text = L"加速";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &boat::button7_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(742, 87);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(86, 23);
			this->button6->TabIndex = 9;
			this->button6->Text = L"直線前進";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &boat::button6_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(411, 161);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(240, 320);
			this->pictureBox2->TabIndex = 8;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(58, 161);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(240, 320);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->splitContainer1);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1203, 591);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"GPS";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 3);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->posShort_distance);
			this->splitContainer1->Panel1->Controls->Add(this->posC);
			this->splitContainer1->Panel1->Controls->Add(this->posB);
			this->splitContainer1->Panel1->Controls->Add(this->posA);
			this->splitContainer1->Panel1->Controls->Add(this->UTC_date);
			this->splitContainer1->Panel1->Controls->Add(this->Direction);
			this->splitContainer1->Panel1->Controls->Add(this->Speed);
			this->splitContainer1->Panel1->Controls->Add(this->WEhemisphere);
			this->splitContainer1->Panel1->Controls->Add(this->Longitude);
			this->splitContainer1->Panel1->Controls->Add(this->SNhemisphere);
			this->splitContainer1->Panel1->Controls->Add(this->Latitute);
			this->splitContainer1->Panel1->Controls->Add(this->Status);
			this->splitContainer1->Panel1->Controls->Add(this->UTC_time);
			this->splitContainer1->Panel1->Controls->Add(this->label15);
			this->splitContainer1->Panel1->Controls->Add(this->label14);
			this->splitContainer1->Panel1->Controls->Add(this->label13);
			this->splitContainer1->Panel1->Controls->Add(this->label12);
			this->splitContainer1->Panel1->Controls->Add(this->label11);
			this->splitContainer1->Panel1->Controls->Add(this->label10);
			this->splitContainer1->Panel1->Controls->Add(this->label9);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label8);
			this->splitContainer1->Panel1->Controls->Add(this->button12);
			this->splitContainer1->Panel1->Controls->Add(this->button11);
			this->splitContainer1->Panel1->Controls->Add(this->label7);
			this->splitContainer1->Panel1->Controls->Add(this->button10);
			this->splitContainer1->Panel1->Controls->Add(this->comboBox2);
			this->splitContainer1->Panel1MinSize = 10;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->pictureBox3);
			this->splitContainer1->Panel2MinSize = 10;
			this->splitContainer1->Size = System::Drawing::Size(1197, 585);
			this->splitContainer1->SplitterDistance = 345;
			this->splitContainer1->SplitterWidth = 2;
			this->splitContainer1->TabIndex = 0;
			// 
			// posShort_distance
			// 
			this->posShort_distance->Location = System::Drawing::Point(190, 194);
			this->posShort_distance->Name = L"posShort_distance";
			this->posShort_distance->Size = System::Drawing::Size(110, 25);
			this->posShort_distance->TabIndex = 25;
			this->posShort_distance->Text = L"Nearest dock";
			this->posShort_distance->UseVisualStyleBackColor = true;
			this->posShort_distance->Click += gcnew System::EventHandler(this, &boat::posShort_distance_Click);
			// 
			// posC
			// 
			this->posC->Location = System::Drawing::Point(47, 194);
			this->posC->Name = L"posC";
			this->posC->Size = System::Drawing::Size(110, 25);
			this->posC->TabIndex = 24;
			this->posC->Text = L"Berth in C";
			this->posC->UseVisualStyleBackColor = true;
			this->posC->Click += gcnew System::EventHandler(this, &boat::posC_Click);
			// 
			// posB
			// 
			this->posB->Location = System::Drawing::Point(190, 146);
			this->posB->Name = L"posB";
			this->posB->Size = System::Drawing::Size(110, 25);
			this->posB->TabIndex = 23;
			this->posB->Text = L"Berth in B";
			this->posB->UseVisualStyleBackColor = true;
			this->posB->Click += gcnew System::EventHandler(this, &boat::posB_Click);
			// 
			// posA
			// 
			this->posA->Location = System::Drawing::Point(47, 146);
			this->posA->Name = L"posA";
			this->posA->Size = System::Drawing::Size(110, 25);
			this->posA->TabIndex = 22;
			this->posA->Text = L"Berth in  A";
			this->posA->UseVisualStyleBackColor = true;
			this->posA->Click += gcnew System::EventHandler(this, &boat::posA_Click);
			// 
			// UTC_date
			// 
			this->UTC_date->AutoSize = true;
			this->UTC_date->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->UTC_date->Location = System::Drawing::Point(170, 525);
			this->UTC_date->Name = L"UTC_date";
			this->UTC_date->Size = System::Drawing::Size(16, 17);
			this->UTC_date->TabIndex = 21;
			this->UTC_date->Text = L"0";
			// 
			// Direction
			// 
			this->Direction->AutoSize = true;
			this->Direction->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->Direction->Location = System::Drawing::Point(170, 485);
			this->Direction->Name = L"Direction";
			this->Direction->Size = System::Drawing::Size(16, 17);
			this->Direction->TabIndex = 20;
			this->Direction->Text = L"0";
			// 
			// Speed
			// 
			this->Speed->AutoSize = true;
			this->Speed->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->Speed->Location = System::Drawing::Point(170, 445);
			this->Speed->Name = L"Speed";
			this->Speed->Size = System::Drawing::Size(16, 17);
			this->Speed->TabIndex = 19;
			this->Speed->Text = L"0";
			// 
			// WEhemisphere
			// 
			this->WEhemisphere->AutoSize = true;
			this->WEhemisphere->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->WEhemisphere->Location = System::Drawing::Point(212, 405);
			this->WEhemisphere->Name = L"WEhemisphere";
			this->WEhemisphere->Size = System::Drawing::Size(54, 17);
			this->WEhemisphere->TabIndex = 18;
			this->WEhemisphere->Text = L"label16";
			// 
			// Longitude
			// 
			this->Longitude->AutoSize = true;
			this->Longitude->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->Longitude->Location = System::Drawing::Point(120, 405);
			this->Longitude->Name = L"Longitude";
			this->Longitude->Size = System::Drawing::Size(16, 17);
			this->Longitude->TabIndex = 17;
			this->Longitude->Text = L"0";
			// 
			// SNhemisphere
			// 
			this->SNhemisphere->AutoSize = true;
			this->SNhemisphere->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->SNhemisphere->Location = System::Drawing::Point(212, 365);
			this->SNhemisphere->Name = L"SNhemisphere";
			this->SNhemisphere->Size = System::Drawing::Size(54, 17);
			this->SNhemisphere->TabIndex = 16;
			this->SNhemisphere->Text = L"label16";
			// 
			// Latitute
			// 
			this->Latitute->AutoSize = true;
			this->Latitute->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->Latitute->Location = System::Drawing::Point(120, 365);
			this->Latitute->Name = L"Latitute";
			this->Latitute->Size = System::Drawing::Size(16, 17);
			this->Latitute->TabIndex = 15;
			this->Latitute->Text = L"0";
			// 
			// Status
			// 
			this->Status->AutoSize = true;
			this->Status->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->Status->Location = System::Drawing::Point(170, 325);
			this->Status->Name = L"Status";
			this->Status->Size = System::Drawing::Size(20, 17);
			this->Status->TabIndex = 1;
			this->Status->Text = L"V";
			// 
			// UTC_time
			// 
			this->UTC_time->AutoSize = true;
			this->UTC_time->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->UTC_time->Location = System::Drawing::Point(170, 285);
			this->UTC_time->Name = L"UTC_time";
			this->UTC_time->Size = System::Drawing::Size(16, 17);
			this->UTC_time->TabIndex = 14;
			this->UTC_time->Text = L"0";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label15->Location = System::Drawing::Point(33, 525);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(75, 17);
			this->label15->TabIndex = 13;
			this->label15->Text = L"UTC_date";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label14->Location = System::Drawing::Point(33, 485);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(42, 17);
			this->label14->TabIndex = 12;
			this->label14->Text = L"航向";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label13->Location = System::Drawing::Point(33, 445);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(42, 17);
			this->label13->TabIndex = 11;
			this->label13->Text = L"速率";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label12->Location = System::Drawing::Point(33, 405);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(42, 17);
			this->label12->TabIndex = 10;
			this->label12->Text = L"經度";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label11->Location = System::Drawing::Point(33, 365);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(42, 17);
			this->label11->TabIndex = 9;
			this->label11->Text = L"緯度";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label10->Location = System::Drawing::Point(33, 325);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(46, 17);
			this->label10->TabIndex = 8;
			this->label10->Text = L"Status";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label9->Location = System::Drawing::Point(33, 285);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(76, 17);
			this->label9->TabIndex = 7;
			this->label9->Text = L"UTC_time";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(123, 237);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(219, 25);
			this->textBox1->TabIndex = 6;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label8->Location = System::Drawing::Point(14, 238);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(76, 17);
			this->label8->TabIndex = 5;
			this->label8->Text = L"原始資料";
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(206, 90);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 23);
			this->button12->TabIndex = 4;
			this->button12->Text = L"關閉GPS";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &boat::button12_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(61, 90);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 23);
			this->button11->TabIndex = 3;
			this->button11->Text = L"定位";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &boat::button11_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label7->Location = System::Drawing::Point(212, 60);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(59, 17);
			this->label7->TabIndex = 2;
			this->label7->Text = L"未連線";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(206, 20);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 23);
			this->button10->TabIndex = 1;
			this->button10->Text = L"GPS連線";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &boat::button10_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(36, 23);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 23);
			this->comboBox2->TabIndex = 0;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &boat::comboBox2_SelectedIndexChanged);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(46, 81);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(749, 421);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 0;
			this->pictureBox3->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(220, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"連線";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &boat::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(440, 36);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"避障";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &boat::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(550, 36);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"跟隨";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &boat::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(660, 36);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"停靠";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &boat::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(770, 36);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"停止";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &boat::button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label1->Location = System::Drawing::Point(880, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"斷線";
			// 
			// GPSPort
			// 
			this->GPSPort->BaudRate = 4800;
			// 
			// timer1
			// 
			this->timer1->Interval = 300;
			this->timer1->Tick += gcnew System::EventHandler(this, &boat::timer1_Tick);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(330, 36);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(81, 24);
			this->button13->TabIndex = 8;
			this->button13->Text = L"啟動馬達";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &boat::button13_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(949, 12);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(180, 83);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 9;
			this->pictureBox4->TabStop = false;
			// 
			// boat
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1210, 713);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"boat";
			this->Text = L"boat";
			this->Load += gcnew System::EventHandler(this, &boat::boat_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//////////////////////////////////////////////////////////////////////////////
//委託
private: delegate void judgement(int x, int y, int d, int f);
private: delegate void arduino(int x, int d);
private: delegate void fps(int t);
private: delegate void park(int d , int x);
private: delegate void route_plan(double deslat, double deslong);
private: delegate void shortplan(double latA, double longA, double latB, double longB, double latC, double longC);
private: delegate void HSV(int h,int s, int v);

//執行緒
Thread^ avoid = gcnew Thread(gcnew ThreadStart(this, &boat::avoidance));
Thread^ follow = gcnew Thread(gcnew ThreadStart(this, &boat::following));
Thread^ berth = gcnew Thread(gcnew ThreadStart(this, &boat::dock));
Thread^ stop_in_a = gcnew Thread(gcnew ThreadStart(this, &boat::StopA));
Thread^ stop_in_b = gcnew Thread(gcnew ThreadStart(this, &boat::StopB));
Thread^ stop_in_c = gcnew Thread(gcnew ThreadStart(this, &boat::StopC));
Thread^ stop_in_shortest = gcnew Thread(gcnew ThreadStart(this, &boat::StopShortest));

Graphics^ picGPS; //the image of picturebox3 

double truelong = 0;  //present google map's longitude
double truelat = 0;  //present google map's latitude
double deviate = 0; // the direction angle get by GPS

static int avoid_number = 0; //the number of beating the avoid
static int follow_number = 0; // the number of beating the follow
static int berth_number = 0; // the number of beating the dock
static int A_number = 0; // the number of beating the berth_in_A
static int B_number = 0; // the number of beating the berth_in_B
static int C_number = 0; // the number of beating the berth_in_C
static int Short_number = 0; // the number of beating the nearest dock
static int GPSimage = 0;  // dont make the picturebox reset
static int HSV_number = 0;
static int HSV_number2 = 0;
static int HSV_number3 = 0;

static int j = 0;  //consider as a judgement for finding destination once
static int judge_dis = 0;

static int direction = 0; // the dircetion of route planning
static double dis = 0; // the distance fo route planning
static int direction2 = 0; // record the previous the direction of route planning
static double dis2 = 0; // record the previous the distance of route planing

private: System::Void boat_Load(System::Object^  sender, System::EventArgs^  e) {
		comboBox1->Items->AddRange(serialPort1->GetPortNames());
		comboBox2->Items->AddRange(GPSPort->GetPortNames());
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;
		button5->Enabled = false;
		button6->Enabled = false;
		button7->Enabled = false;
		button8->Enabled = false;
		button9->Enabled = false;
		button11->Enabled = false;
		button12->Enabled = false;
		button13->Enabled = false;
		posA->Enabled = false;
		posB->Enabled = false;
		posC->Enabled = false;
		posShort_distance->Enabled = false;
	}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	//arduino
	serialPort1->PortName = comboBox1->Text;
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//arduino連線
	if (serialPort1->IsOpen == false) {
		serialPort1->Open();
		label1->Text = "連線";
		button1->Enabled = false;
		button2->Enabled = true;
		button3->Enabled = true;
		button4->Enabled = true;
		button5->Enabled = true;
		button6->Enabled = true;
		button7->Enabled = true;
		button8->Enabled = true;
		button9->Enabled = true;
		button13->Enabled = true;
	}
}

private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	//GSP
	GPSPort->PortName = comboBox2->Text;
}

private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	//GPS連線
	if (GPSPort->IsOpen == false) {
		GPSPort->Open();
		label7->Text = "GPS連線";
		button10->Enabled = false;
		button11->Enabled = true;

	}
}

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	//stop image
	//make the parameter return to zero
	truelong = 0;  //present google map's longitude
	truelat = 0;  //present google map's latitude
	deviate = 0; // the direction angle get by GPS

	A_number = 0; // the number of beating the berth_in_A
	B_number = 0; // the number of beating the berth_in_B
	C_number = 0; // the number of beating the berth_in_C
	Short_number = 0; // the number of beating the nearest dock
	GPSimage = 0;  // dont make the picturebox reset

	 j = 0;  //consider as a judgement for finding destination once

	direction = 0; // the dircetion of route planning
	dis = 0; // the distance fo route planning
	direction2 = 0; // record the previous the direction of route planning
	dis2 = 0; // record the previous the distance of route planing
	serialPort1->Write("s");
	label24->Text = "停止";

	if (follow->IsAlive == true) {
		follow->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
		button3->Enabled = true;

	}

	if (avoid->IsAlive == true) {
		avoid->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
		button2->Enabled = true;
	}

	if (berth->IsAlive == true) {
		berth->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
		button4->Enabled = true;

	}
	
	
	if (stop_in_a->IsAlive == true) {
		stop_in_a->Suspend();
	}

	if (stop_in_b->IsAlive == true) {
		stop_in_b->Suspend();
	}

	if (stop_in_c->IsAlive == true) {
		stop_in_c->Suspend();
	}

	if (stop_in_shortest->IsAlive == true) {
		stop_in_shortest->Suspend();
	}
	
}

private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
	//close GPS
	GPSPort->Close();
	timer1->Stop();
	GPSimage = 0;
	direction = 0; // the dircetion of route planning
	dis = 0; // the distance fo route planning
	direction2 = 0; // record the previous the direction of route planning
	dis2 = 0; // record the previous the distance of route planing

	button10->Enabled = true;
	button12->Enabled = false;
	button11->Enabled = false;
	posA->Enabled = false;
	posB->Enabled = false;
	posC->Enabled = false;
	posShort_distance->Enabled = false;
}

private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	//定位
	timer1->Start();
	button11->Enabled = false;
	button12->Enabled = true;
	posA->Enabled = true;
	posB->Enabled = true;
	posC->Enabled = true;
	posShort_distance->Enabled = true;
}

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	//定位，GPS資料處理
	textBox1->Text = GPSPort->ReadLine();
	Mat img_map;  //x:749 , y: 421     實際用745,416
	Mat position;
	img_map = imread("swimming5.jpg", -1);
	cvtColor(img_map, img_map, COLOR_BGR2BGRA);

	if (textBox1->Text->Contains("$GPRMC")) {
		System::String^ GPSinfo = textBox1->Text;
		const char*  GPSchardata = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(GPSinfo)).ToPointer();
		string data = GPSchardata;  //最初的資料
		
		int empty = 0;
		double latitude2;
		double longitude2;
		static double x = 0;  //presernt X of location
		static double y = 0; //presernt Y of location
		static double x2 = 0; // previous X of location
		static double y2 = 0; // prvious Y of location
		

		Pen^ blackPen = gcnew Pen(Color::Black, 3.0f);
		Pen^ redPen = gcnew Pen(Color::Red, 3.0f);
		System::Drawing::Font^ myFont = gcnew System::Drawing::Font("Calibri", 14);

		picGPS = pictureBox3->CreateGraphics();
		IntPtr ptr(img_map.ptr());
		Bitmap^ img = gcnew Bitmap(img_map.cols, img_map.rows, img_map.step, System::Drawing::Imaging::PixelFormat::Format32bppRgb, ptr);
		RectangleF siz(0, 0, pictureBox3->Width, pictureBox3->Height);

		if (x != x2 || y != y2) {
			x2 = x;
			y2 = y;
			picGPS->DrawEllipse(blackPen, x2, y2, 3, 3);
		}

		//UCT時間
		string info12 = data.substr(pos(data) + 1); //逗號在6
		string utc_time;
		string info11;
		utc_time = info12.substr(0, pos(info12));
		info11 = info12.substr(pos(info12) + 1);
		if (utc_time == " ") {
			UTC_time->Text = empty.ToString();
		}

		System::String^ str1 = gcnew System::String(utc_time.c_str());
		UTC_time->Text = str1;   //
		//GPS狀態
		string status;
		string info10;
		status = info11.substr(0, pos(info11));
		info10 = info11.substr(pos(info11) + 1);

		System::String^ str2 = gcnew System::String(status.c_str());
		Status->Text = str2; //
		//緯度
		string latitude;
		string info9;
		latitude = info10.substr(0, pos(info10));
		info9 = info10.substr(pos(info10) + 1);
		latitude2 = atof(latitude.c_str());
		latitude2 = latitude2 / 100;
		int integr = floor(latitude2);
		truelat = integr + ((latitude2 - integr) * 100 / 60);  // the latitude of google maps

		string finallat = to_string(truelat);
		if (latitude == "") {
			Latitute->Text = empty.ToString();
		}
		else {
			System::String^ str3 = gcnew System::String(finallat.c_str());
			Latitute->Text = str3;
		}  //
		//南北半球
		string NorS;
		string info8;
		NorS = info9.substr(0, pos(info9));
		info8 = info9.substr(pos(info9) + 1);
		if (NorS == "") {
			SNhemisphere->Text = "無偵測值";
		}
		else {
			System::String^ str4 = gcnew System::String(NorS.c_str());
			SNhemisphere->Text = str4;
		}  //
		//經度
		string longitude;
		string info7;
		longitude = info8.substr(0, pos(info8));
		info7 = info8.substr(pos(info8) + 1);
		longitude2 = atof(longitude.c_str());
		longitude2 = longitude2 / 100;
		int integr2 = floor(longitude2);
		truelong = integr2 + ((longitude2 - integr2) * 100 / 60); //the longitude of google maps

		string finallong = to_string(truelong);
		if (longitude == "") {
			Longitude->Text = empty.ToString();
		}
		else {
			System::String^ str5 = gcnew System::String(finallong.c_str());
			Longitude->Text = str5;
		}  //
		//東西半球
		string EorW;
		string info6;
		EorW = info7.substr(0, pos(info7));
		info6 = info7.substr(pos(info7) + 1);
		if (EorW == "") {
			WEhemisphere->Text = "無偵測值";
		}
		else {
			System::String^ str6 = gcnew System::String(EorW.c_str());
			WEhemisphere->Text = str6;
		}  //
		//速率
		string speed;
		string info5;
		speed = info6.substr(0, pos(info6));
		info5 = info6.substr(pos(info6) + 1);
		if (speed == "") {
			Speed->Text = empty.ToString();
		}
		else {
			System::String^ str7 = gcnew System::String(speed.c_str());
			Speed->Text = str7;
		}  //
		//航向
		string angle;
		string info4;
		angle = info5.substr(0, pos(info5));
		info4 = info5.substr(pos(info5) + 1);
		deviate = atof(angle.c_str());
		if (angle == "") {
			Direction->Text = empty.ToString();
		}
		else {
			System::String^ str8 = gcnew System::String(angle.c_str());
			Direction->Text = str8;
		}  //
		//日期
		string utc_date;
		string info3;
		utc_date = info4.substr(0, pos(info4));
		info3 = info4.substr(pos(info4) + 1);
		if (utc_date == "") {
			UTC_date->Text = empty.ToString();
		}
		else {
			System::String^ str9 = gcnew System::String(utc_date.c_str());
			UTC_date->Text = str9;
		}  //
		//detect location
		if (truelong >120.26385  && truelong < 120.2641) {
			if (truelat > 22.62224 && truelat < 22.62237) {
				x =  2980000 * (truelong - 120.26385);
				y = -3200000* (truelat - 22.62237);
			}
		}
		//double latC = 22.6223; // the latitude of point C
		//double longC = 120.2641; // the longitude of point C

		if (GPSimage < 1) {
			picGPS->DrawImage(img, siz);
			picGPS->DrawString("A", myFont, Brushes::Blue, 3, 224);
			picGPS->DrawString("B", myFont, Brushes::Blue, 447, 3);
			picGPS->DrawString("C", myFont, Brushes::Blue, 730, 224);
			picGPS->DrawEllipse(redPen, 3, 224, 3, 3);
			picGPS->DrawEllipse(redPen, 447, 3, 3, 3);
			picGPS->DrawEllipse(redPen, 745, 224, 3, 3);
			GPSimage++;
		}
			
		picGPS->DrawEllipse(redPen,x, y, 3, 3);


	}
}

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	//直線
	label24->Text = "直線前進";
	serialPort1->Write("f");
}

private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	//加速
	label24->Text = "加速";
	serialPort1->Write("+");
}

private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	//left
	label24->Text = "左轉";
	serialPort1->Write("l");
}

private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	//right
	label24->Text = "右轉";
	serialPort1->Write("r");
}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//避障
	avoid_number++;
	label24->Text = "避障";
	if (follow->IsAlive == true) {
		follow->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
		button3->Enabled = true;
	}


	if (berth->IsAlive == true) {
		berth->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
		button4->Enabled = true;
	}


	if (stop_in_a->IsAlive == true) {
		stop_in_a->Suspend();
	}

	if (stop_in_b->IsAlive == true) {
		stop_in_b->Suspend();
	}
	
	if (stop_in_c->IsAlive == true) {
		stop_in_c->Suspend();
	}

	if (stop_in_shortest->IsAlive == true) {
		stop_in_shortest->Suspend();
	}

	if (avoid_number >= 2){
		avoid->Resume();
		button2->Enabled = false;
	}
	else if (avoid_number <=1 ){
		avoid->IsBackground = true;
		avoid->Start();
		button2->Enabled = false;
	}
	
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	//跟隨
	label24->Text = "跟隨";
	follow_number++;
	if (avoid->IsAlive == true) {
		avoid->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
		button2->Enabled = true;
	}


	if (berth->IsAlive == true) {
		berth->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
		button4->Enabled = true;
	}


	if (stop_in_a->IsAlive == true) {
		stop_in_a->Suspend();
	}

	if (stop_in_b->IsAlive == true) {
		stop_in_b->Suspend();
	}

	if (stop_in_c->IsAlive == true) {
		stop_in_c->Suspend();
	}

	if (stop_in_shortest->IsAlive == true) {
		stop_in_shortest->Suspend();
	}
	

	if (follow_number >= 2){
        follow->Resume();
		button3->Enabled = false;
	}
	else if(follow_number <= 1){
        follow->IsBackground = true;
		follow->Start();
		button3->Enabled = false;
	}
		
}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	//停靠
	label24->Text = "停靠";
	berth_number++;
	if (avoid->IsAlive == true) {
		avoid->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
		button2->Enabled = true;

	}
	
	
	if (follow->IsAlive == true) {
		follow->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
		button3->Enabled = true;
	}


	if (stop_in_a->IsAlive == true) {
		stop_in_a->Suspend();
	}

	if (stop_in_b->IsAlive == true) {
		stop_in_b->Suspend();
	}

	if (stop_in_c->IsAlive == true) {
		stop_in_c->Suspend();
	}

	if (stop_in_shortest->IsAlive == true) {
		stop_in_shortest->Suspend();
	}


	if (berth_number >= 2) {
		berth->Resume();
		button4->Enabled = false;
	}
	else if (berth_number <= 1) {
		berth->IsBackground = true;
		berth->Start();
		button4->Enabled = false;
	}
	
}

private: void avoidance() { ////////////////////////////////////////////避障 影像
	Mat img = imread("30cm_greenball.jpg", 3);
	Mat img2;
	Mat img3;
	Mat img4;

	cvtColor(img, img2, COLOR_BGR2HSV);
	const Scalar hsvGreenLo(78, 43, 46);
	const Scalar hsvGreenHi(99, 255, 255);

	inRange(img2, hsvGreenLo, hsvGreenHi, img3);
	medianBlur(img3, img4, 7);
	GaussianBlur(img4, img4, cv::Size(7, 7), 0, 0);

	vector<Vec3f> circles2;

	HoughCircles(img4, circles2, HOUGH_GRADIENT, 2, 50, 200, 100);
	
	int f;  // f=(p*d)/w

	for (int i = 0; i < circles2.size(); i++) {
		cv::Point center(cvRound(circles2[i][0]), cvRound(circles2[i][1]));
		int radius2 = cvRound(circles2[i][2]);
		circle(img4, center, radius2, Scalar(0, 255, 0), 3, 8, 0);

		f = (2 * radius2 * 30) / 15.9;

	}


	////////////////////////////////////////////////////
	VideoCapture cap(0);
	Mat frame;
	Mat hsvImage;
	Mat imgThresholded;
	Mat midimg;
	int h = 78;
	int s = 190;
	int v = 76;
	double t = 0;
	//x全長640 y 320
	while (true) {
		cap.read(frame);
		t = (double)cv::getTickCount();
		if (cv::waitKey(10) == 10) { break; }
		if (cap.isOpened()) {
			t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
			int frames_num = 1 / t;
			fps^ ftime = gcnew fps(this, &boat::FPS);
			this->Invoke(ftime, gcnew int(frames_num));
		}
		
		if (frame.empty()) {
			frame.release();
			cap.release();
			Thread::Sleep(1500);
			cap.open(0);
		}

		else {
			cvtColor(frame, hsvImage, COLOR_BGR2HSV);

			const Scalar hsvGreenLow(h, s, v);
			const Scalar hsvGreenHih(99, 255, 255);

			inRange(hsvImage, hsvGreenLow, hsvGreenHih, imgThresholded);//閾值設定 辨識綠色
			threshold(imgThresholded, imgThresholded, 1, 255, THRESH_BINARY);
			bilateralFilter(imgThresholded, midimg, 10, 75, 80);
			medianBlur(midimg, midimg, 9);
			GaussianBlur(midimg, midimg, cv::Size(1, 1), 0, 0);

			vector<vector<cv::Point>> contourss;
			vector<cv::Vec4i>hierarchy;

			findContours(midimg, contourss, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);

			vector<RotatedRect> minRect(contourss.size());

			int diameter = 0;
			int x = 0;
			int y = 0;
			int d = 0;

			for (int i = 0; i < contourss.size(); i++) { //找中心
				minRect[i] = minAreaRect(contourss[i]);
				Point2f peak[4];
				minRect[i].points(peak);
				x = minRect[i].center.x;
				y = minRect[i].center.y;
			}

			for (int x = 0; x < contourss.size(); x++) {  //畫出
				if (minRect[x].size.height > 0) {
					Point2f points[4];
					minRect[x].points(points);
					for (int y = 0; y < 4; y++)
						line(frame, points[y], points[(y + 1) % 4], Scalar(0, 0, 255), 3, 8);
				}
			}
			for (int j = 0; j < contourss.size(); j++) //(int)contours.size()
			{
				int length = arcLength(contourss[j], true);
				if (length > 7) {
					diameter = length/4 ;  //proportion
				}
			}

			if (diameter != 0) {
				d = ((15 * f) / diameter) - 7;
			}


			Graphics^ pic = pictureBox1->CreateGraphics();
			IntPtr ptr(frame.ptr());
			Bitmap^ img8 = gcnew Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			RectangleF siz(0, 0, pictureBox1->Width, pictureBox1->Height);
			pic->DrawImage(img8, siz);

			Graphics^pic2 = pictureBox2->CreateGraphics();
			IntPtr ptr2(midimg.ptr());			
			Bitmap^ img9 = gcnew Bitmap(midimg.cols, midimg.rows, midimg.step, System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr2);
			RectangleF siz2(0, 0, pictureBox2->Width, pictureBox2->Height);
			pic2->DrawImage(img9, siz2);

			judgement^ number = gcnew judgement(this, &boat::weightpoint);//weightpoint and distance
			this->Invoke(number, gcnew int(x), (y), (d), (f));

			arduino^ control = gcnew arduino(this, &boat::avoidduino); //Arduino
			this->Invoke(control, gcnew int(x), (d));

			HSV^ adjustment = gcnew HSV(this, &boat::hsv);
			this->Invoke(adjustment, gcnew int(h) ,(s), (v));


			if (h != hScrollBar1->Value || s != hScrollBar2->Value || v != hScrollBar3->Value) {
				h = hScrollBar1->Value;
				s = hScrollBar2->Value;
				v = hScrollBar3->Value;
			}
			

			delete img8;
			delete img9;

			frame.release();
			imgThresholded.release();
			midimg.release();
			hsvImage.release();

			contourss.clear();
			hierarchy.clear();
		}
		if (waitKey(33) >= 0) {
			break;
		}



	}

}

private: void following() { /////////////////////////////////////跟隨 影像
	Mat img = imread("30cm_greenball.jpg", 3);
	Mat img2;
	Mat img3;
	Mat img4;

	cvtColor(img, img2, COLOR_BGR2HSV);
	const Scalar hsvGreenLo(78, 43, 46);
	const Scalar hsvGreenHi(99, 255, 255);

	inRange(img2, hsvGreenLo, hsvGreenHi, img3);
	medianBlur(img3, img4, 7);
	GaussianBlur(img4, img4, cv::Size(7, 7), 0, 0);

	vector<Vec3f> circles2;

	HoughCircles(img4, circles2, HOUGH_GRADIENT, 2, 50, 200, 100);

	int f;  // f=(p*d)/w

	for (int i = 0; i < circles2.size(); i++) {
		cv::Point center(cvRound(circles2[i][0]), cvRound(circles2[i][1]));
		int radius2 = cvRound(circles2[i][2]);
		circle(img4, center, radius2, Scalar(0, 255, 0), 3, 8, 0);

		f = (2 * radius2 * 30) / 15.9;

	}



	////////////////////////////////////////////////////
	VideoCapture cap(0);
	Mat frame;
	Mat imgThresholded;
	Mat hsvimage;
	Mat midimg;
	int h = 81;
	int s = 190;
	int v = 25;
	double t = 0;
	while (true)
	{
		cap.read(frame);
		t = (double)cv::getTickCount();
		if (cv::waitKey(10) == 10) { break; }
		if (cap.isOpened()) {
			t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
			int frames_num = 1 / t;
			fps^ ftime = gcnew fps(this, &boat::FPS);
			this->Invoke(ftime, gcnew int(frames_num));
		}

		if (frame.empty()) {
			frame.release();
			cap.release();
			Thread::Sleep(1500);
			cap.open(0);
		}
		else {
			cvtColor(frame, hsvimage, COLOR_BGR2HSV);

			const Scalar greenlow(h, s, v);
			const Scalar greenhigh(99, 255, 255);

			inRange(hsvimage, greenlow, greenhigh, imgThresholded);//閾值設定 辨識綠色
			threshold(imgThresholded, imgThresholded, 1, 255, THRESH_BINARY);
			bilateralFilter(imgThresholded, midimg, 10, 75, 80);
			medianBlur(midimg, midimg, 9);
			GaussianBlur(midimg, midimg, cv::Size(1, 1), 0, 0);

			vector<vector<cv::Point>>contours;
			vector<cv::Vec4i>hierarchy;

			findContours(midimg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

			vector<RotatedRect> minRect(contours.size());

			int x = 0;
			int y = 0;
			int d = 0;

			for (int i = 0; i < contours.size(); i++) { //找中心
				minRect[i] = minAreaRect(contours[i]);
				Point2f peak[4];
				minRect[i].points(peak);
				x = minRect[i].center.x;
				y = minRect[i].center.y;
			}

			for (int x = 0; x < contours.size(); x++) {  //畫出
				if (minRect[x].size.height > 0) {
					Point2f points[4];
					minRect[x].points(points);
					for (int y = 0; y < 4; y++)
						line(frame, points[y], points[(y + 1) % 4], Scalar(0, 0, 255), 3, 8);
				}
			}

			for (int j = 0; j < contours.size(); j++) //(int)contours.size()
			{
				int length = arcLength(contours[j], true);
				if (length > 7) {
					d = (f * 29.7) / (length *0.27 );  //proportion
				}
			}

			Graphics^ pic = pictureBox1->CreateGraphics();
			IntPtr ptr(frame.ptr());
			Bitmap^ img8 = gcnew Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			RectangleF siz(0, 0, pictureBox1->Width, pictureBox1->Height);
			pic->DrawImage(img8, siz);

			Graphics^pic2 = pictureBox2->CreateGraphics();
			IntPtr ptr2(midimg.ptr());			
			Bitmap^ img9 = gcnew Bitmap(midimg.cols, midimg.rows, midimg.step, System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr2);
			RectangleF siz2(0, 0, pictureBox2->Width, pictureBox2->Height);
			pic2->DrawImage(img9, siz2);

			judgement^ numberf = gcnew judgement(this, &boat::weightpoint); //重心與距離
			this->Invoke(numberf, gcnew int(x), (y), (d), (f));

			arduino^ controlf = gcnew arduino(this, &boat::followduino); //arduino
			this->Invoke(controlf, gcnew int(x), (d));

			HSV^ adjustment = gcnew HSV(this, &boat::hsv2);
			this->Invoke(adjustment, gcnew int(h), (s), (v));

			if (h != hScrollBar1->Value || s != hScrollBar2->Value || v != hScrollBar3->Value) {
				h = hScrollBar1->Value;
				s = hScrollBar2->Value;
				v = hScrollBar3->Value;
			}

			contours.clear();
			hierarchy.clear();

			delete img8;
			delete img9;

			frame.release();
			imgThresholded.release();
			midimg.release();
			hsvimage.release();
		}

		if (waitKey(33) >= 0) {
			break;
		}
	}
	
}

private: void dock() {  ///////////////////////////////////////////停靠 影像
	//using the image processing to get the distance
	//using latitude and longitude to get the angle
	Mat img = imread("30cm_greenball.jpg", 3);
	Mat img2;
	Mat img3;
	Mat img4;

	cvtColor(img, img2, COLOR_BGR2HSV);
	const Scalar hsvGreenLo(78, 43, 46);
	const Scalar hsvGreenHi(99, 255, 255);

	inRange(img2, hsvGreenLo, hsvGreenHi, img3);
	medianBlur(img3, img4, 7);
	GaussianBlur(img4, img4, cv::Size(7, 7), 0, 0);

	vector<Vec3f> circles2;

	HoughCircles(img4, circles2, HOUGH_GRADIENT, 2, 50, 200, 100);

	int f;  // f=(p*d)/w

	for (int i = 0; i < circles2.size(); i++) {
		cv::Point center(cvRound(circles2[i][0]), cvRound(circles2[i][1]));
		int radius2 = cvRound(circles2[i][2]);
		circle(img4, center, radius2, Scalar(0, 255, 0), 3, 8, 0);

		f = (2 * radius2 * 30) / 15.9;

	}

	////////////////////////////////////////////////////
	VideoCapture cap(0);
	Mat frame;
	Mat imgThresholded;
	Mat hsvimage;
	Mat midimg;
	int h = 0;
	int s = 0;
	int v = 0;
	double t = 0;
	while (true)
	{
		cap.read(frame);
		t = (double)cv::getTickCount();
		if (cv::waitKey(10) == 10) { break; }
		if (cap.isOpened()) {
			t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
			int frames_num = 1 / t;
			fps^ ftime = gcnew fps(this, &boat::FPS);
			this->Invoke(ftime, gcnew int(frames_num));
		}

		if (frame.empty()) {
			frame.release();
			cap.release();
			Thread::Sleep(1500);
			cap.open(0);
		}
		else {
			cvtColor(frame, hsvimage, COLOR_BGR2HSV);

			const Scalar greenlow(h, s, v);
			const Scalar greenhigh(10, 255, 255);

			inRange(hsvimage, greenlow, greenhigh, imgThresholded);//閾值設定 辨識綠色
			threshold(imgThresholded, imgThresholded, 1, 255, THRESH_BINARY);
			bilateralFilter(imgThresholded, midimg, 10, 75, 80);
			medianBlur(midimg, midimg, 9);
			GaussianBlur(midimg, midimg, cv::Size(1, 1), 0, 0);

			vector<vector<cv::Point>>contours;
			vector<cv::Vec4i>hierarchy;

			findContours(midimg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

			vector<RotatedRect> minRect(contours.size());

			int x = 0;
			int y = 0;
			int d = 0;

			for (int i = 0; i < contours.size(); i++) { //找中心
				minRect[i] = minAreaRect(contours[i]);
				Point2f peak[4];
				minRect[i].points(peak);
				x = minRect[i].center.x;
				y = minRect[i].center.y;
			}

			for (int x = 0; x < contours.size(); x++) {  //畫出
				if (minRect[x].size.height > 0) {
					Point2f points[4];
					minRect[x].points(points);
					for (int y = 0; y < 4; y++)
						line(frame, points[y], points[(y + 1) % 4], Scalar(0, 0, 255), 3, 8);
				}
			}

			for (int j = 0; j < contours.size(); j++) //(int)contours.size()
			{
				int length = arcLength(contours[j], true);
				if (length > 7) {
					d = (f * 28* 0.707) / (length * 0.2 );  //proportion 45度
				}
			}

			Graphics^ pic = pictureBox1->CreateGraphics();
			IntPtr ptr(frame.ptr());
			Bitmap^ img8 = gcnew Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			RectangleF siz(0, 0, pictureBox1->Width, pictureBox1->Height);
			pic->DrawImage(img8, siz);

			Graphics^ pic2 = pictureBox2->CreateGraphics();
			IntPtr ptr2(midimg.ptr());
			Bitmap^ img9 = gcnew Bitmap(midimg.cols, midimg.rows, midimg.step, System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr2);
			RectangleF siz2(0, 0, pictureBox2->Width, pictureBox2->Height);
			pic2->DrawImage(img9, siz2);

			judgement^ numberpark = gcnew judgement(this, &boat::weightpoint); //重心與距離
			this->Invoke(numberpark, gcnew int(x), (y), (d), (f));

			park^ dista = gcnew park(this, &boat::dockduino);
			this->Invoke(dista, gcnew int(d), (x));

			HSV^ adjustment = gcnew HSV(this, &boat::hsv3);
			this->Invoke(adjustment, gcnew int(h), (s), (v));

			if (h != hScrollBar1->Value || s != hScrollBar2->Value || v != hScrollBar3->Value) {
				h = hScrollBar1->Value;
				s = hScrollBar2->Value;
				v = hScrollBar3->Value;
			}

			contours.clear();
			hierarchy.clear();

			delete img8;
			delete img9;

			frame.release();
			imgThresholded.release();
			midimg.release();
			hsvimage.release();

		}
		if (waitKey(33) >= 0) {
				break;
		}
	}
}

private:void weightpoint(int x, int y, int d , int f) { ////////////////重心 距離 焦距
	xposition->Text = x.ToString();
	yposition->Text = y.ToString();
	Distance->Text = d.ToString();
	Focus->Text = f.ToString();
}

private:void avoidduino(int x, int d) { //////////////////////////////避障 arduino
	if (x == 0 && d == 0) {
		serialPort1->Write("1"); //straight faster
	}
	
	if (d<130) {
		if (x > 320 && x <600) {
			serialPort1->Write("l"); //turn left

		}
		else if (x < 319 && x>100) {
			serialPort1->Write("r"); // turn right

		}
		else if (x > 700) {
			serialPort1->Write("s");
		}
	}

	else if (d > 140 && d < 3500) {
		serialPort1->Write("f");// straight slower
	}
	else if (d > 3501) {
		serialPort1->Write("s");
	}
	
}

private:void followduino(int x, int d) { /////////////////////////////跟隨 arduino
	if (x > 420 && x < 640) {
		serialPort1->Write("r");
		
	}
	else if (x < 220 && x > 0) {
		serialPort1->Write("l"); //turn left
	}
	else {
		if (d > 100 && d < 250) {
			serialPort1->Write("1");// straight faster
		}
		else if (d < 60 && d > 31) {
			serialPort1->Write("f");// straight slower
		}
		else if (d< 30) {
			serialPort1->Write("s");
		}
		else if (61 < d < 99) {
			serialPort1->Write("f");// straight slower
		}
		else if (d > 750) {
			serialPort1->Write("s");
		}
	}

}

private:void dockduino(int d , int x) { /////////////////////////////////停靠 arduino
//the latitude and longitude of the destination
//it will be designed in the demo
	double deslat = 0;
	double deslong = 0;

	double angle = get_angle(truelat, truelong, deslat, deslong); // calculate the angle
	//ensure the location which it can dock in
	//design the boat how to dock in the fixed point
	if (j < 1) {  // find the objective
		if (x < 280 || x > 360) {
			serialPort1->Write("0"); //  right rotation
		}
		else {
			serialPort1->Write("f");
			j = 1;
		}
	}
	else {// after find the objective , the controlling method
		if (d > 200 ) {
			if (angle < 90 && angle > 0) {  // 45 degree
				if (angle < 42) {
					serialPort1->Write("l");
					j = 2; //judging previous command is left 
				}
				else if (angle > 48) {
					serialPort1->Write("r");
					j = 3; //judhing previous command is right
				}
				else {
					serialPort1->Write("f");
				}
			}
			else if (angle < 180 && angle > 90) { // 135 degree
				if (angle < 132) {
					serialPort1->Write("l");
					j = 2; //judging previous command is left 
				}
				else if (angle > 138) {
					serialPort1->Write("r");
					j = 3; //judhing previous command is right
				}
				else {
					serialPort1->Write("f");
				}
			}
			else if (angle < 270 && angle >180) { // 225 degree
				if (angle < 222) {
					serialPort1->Write("l");
					j = 2; //judging previous command is left 
				}
				else if (angle > 228) {
					serialPort1->Write("r");
					j = 3; //judhing previous command is right
				}
				else {
					serialPort1->Write("f");
				}
			}
			else if (angle < 360 && angle > 270) { // 315 degree
				if (angle < 312) {
					serialPort1->Write("l");
					j = 2; //judging previous command is left 
				}
				else if (angle > 318) {
					serialPort1->Write("r");
					j = 3; //judhing previous command is right
				}
				else {
					serialPort1->Write("f");
				}
			}
			else if (d == 0 && x == 0) { //lose the goal
				if (j == 2) { //previous command is left
					serialPort1->Write("r");
				}
				else if (j == 3) {//previous command is right
					serialPort1->Write("l");
				}
			}
		}
		else if (d < 199 && d > 120) {
			serialPort1->Write("s");
		}
		else if (d <= 119) {
			if (angle < 90 && angle > 0) {
				serialPort1->Write("0"); // turn right
				if (d = 0 || d > 200) {
					serialPort1->Write("s");
				}
			}
			else if (angle < 180 && angle > 90) {
				serialPort1->Write("2"); // turn left
				if (d = 0 || d > 200) {
					serialPort1->Write("s");
				}
			}
			else if (angle < 270 && angle >180) {
				serialPort1->Write("0"); // turn right
				if (d = 0 || d > 200) {
					serialPort1->Write("s");
				}
			}
			else if (angle < 360 && angle > 270) {
				serialPort1->Write("2"); // turn left 
				if (d = 0 || d > 200) {
					serialPort1->Write("s");
				}
			}
			
		}
		else if (d > 1250) {
			serialPort1->Write("s");
		}
	}
}

private:void FPS(int f_p_s) {
	label17->Text = f_p_s.ToString();
}

private:void hsv(int h, int s ,int v) { // avoid HSV
	if (HSV_number < 1) {
		hScrollBar1->Value = h;
		hScrollBar2->Value = s;
		hScrollBar3->Value = v;
		HSV_number = 2;
	}
	label18->Text = h.ToString();
	label19->Text = s.ToString();
	label20->Text = v.ToString();
}

private:void hsv2(int h, int s, int v) { //follow HSV
	if (HSV_number2 < 1) {
		hScrollBar1->Value = h;
		hScrollBar2->Value = s;
		hScrollBar3->Value = v;
		HSV_number2 = 2;
	}
	label18->Text = h.ToString();
	label19->Text = s.ToString();
	label20->Text = v.ToString();
}

private:void hsv3(int h, int s, int v) { // berth HSV
	if (HSV_number3 < 1) {
		hScrollBar1->Value = h;
		hScrollBar2->Value = s;
		hScrollBar3->Value = v;
		HSV_number3 = 2;
	}
	label18->Text = h.ToString();
	label19->Text = s.ToString();
	label20->Text = v.ToString();
}

private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	serialPort1->Write("i");  // switch on the brushless motor
	label24->Text = "啟動馬達";
}

private: System::Void posA_Click(System::Object^  sender, System::EventArgs^  e) {
	//route planning of "A" is starting
	A_number++;

	if (avoid->IsAlive == true) {
		avoid->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}

	if (follow->IsAlive == true) {
		follow->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}

	if (berth->IsAlive == true) {
		berth->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}

	if (stop_in_b->IsAlive == true) {
		stop_in_b->Suspend();
	}
	
	if (stop_in_c->IsAlive == true) {
		stop_in_c->Suspend();
	}
	
	if (stop_in_shortest->IsAlive == true) {
		stop_in_shortest->Suspend();
	}

	if (A_number >= 2) {
		stop_in_a->Resume();
	}
	else if (A_number <= 1) {
		stop_in_a->IsBackground == true;
		stop_in_a->Start();
	}

}

private: System::Void posB_Click(System::Object^  sender, System::EventArgs^  e) {
	//route planning of "B" is starting
	B_number++;

	if (avoid->IsAlive == true) {
		avoid->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}

	if (follow->IsAlive == true) {
		follow->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}

	if (berth->IsAlive == true) {
		berth->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}

	if (stop_in_a->IsAlive == true) {
		stop_in_a->Suspend();
	}

	if (stop_in_c->IsAlive == true) {
		stop_in_c->Suspend();
	}

	if (stop_in_shortest->IsAlive == true) {
		stop_in_shortest->Suspend();
	}

	if (B_number >= 2) {
		stop_in_b->Resume();
	}
	else if (B_number <= 1) {
		stop_in_b->IsBackground == true;
		stop_in_b->Start();
	}

}

private: System::Void posC_Click(System::Object^  sender, System::EventArgs^  e) {
	//route planning of "C" is starting
	C_number++;

	if (avoid->IsAlive == true) {
		avoid->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}

	if (follow->IsAlive == true) {
		follow->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}

	if (berth->IsAlive == true) {
		berth->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}

	if (stop_in_b->IsAlive == true) {
		stop_in_b->Suspend();
	}

	if (stop_in_a->IsAlive == true) {
		stop_in_a->Suspend();
	}

	if (stop_in_shortest->IsAlive == true) {
		stop_in_shortest->Suspend();
	}

	if (C_number >= 2) {
		stop_in_c->Resume();
	}
	else if (C_number <= 1) {
		stop_in_c->IsBackground == true;
		stop_in_c->Start();
	}

}

private: System::Void posShort_distance_Click(System::Object^  sender, System::EventArgs^  e) {
	//route planning of "shortest" is starting
	Short_number++;

	if (avoid->IsAlive == true) {
		avoid->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}
	else if (follow->IsAlive == true) {
		follow->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}
	else if (berth->IsAlive == true) {
		berth->Suspend();
		pictureBox1->Refresh();
		pictureBox2->Refresh();
	}
	else if (stop_in_b->IsAlive == true) {
		stop_in_b->Suspend();
	}
	else if (stop_in_c->IsAlive == true) {
		stop_in_c->Suspend();
	}
	else if (stop_in_a->IsAlive == true) {
		stop_in_a->Suspend();
	}

	if (Short_number >= 2) {
		stop_in_shortest->Resume();
	}
	else if (Short_number <= 1) {
		stop_in_shortest->IsBackground == true;
		stop_in_shortest->Start();
	}

}

private: void StopA() {  
// route planning of A 
// arduino control
	double latA = 22.6223; // the latitude of point A
	double longA = 120.26385; // the longitude of point A 
	double x;
	double y;
	if (truelong >120.26385  && truelong < 120.2641) {
		if (truelat > 22.62224 && truelat < 22.62237) {
			x = 2980000 * (truelong - 120.26385);
			y = -3200000 * (truelat - 22.62237);
		}
	}
	Pen^ bluePen = gcnew Pen(Color::Blue, 3.0f);
	picGPS->DrawLine(bluePen, 3, 224, x, y);

	while (true)
	{
		route_plan^ A_point = gcnew route_plan(this, &boat::A_plan);
		this->Invoke(A_point, gcnew double(latA), (longA));
	}
}

private: void StopB() {
// route planning of B
// arduino control
	double latB = 22.62237; // the latitude of point B
	double longB = 120.2640; // the longitude of point B 
	double x;
	double y;
	if (truelong >120.26385  && truelong < 120.2641) {
		if (truelat > 22.62224 && truelat < 22.62237) {
			x = 2980000 * (truelong - 120.26385);
			y = -3200000 * (truelat - 22.62237);
		}
	}
	Pen^ bluePen = gcnew Pen(Color::Blue, 3.0f);
	picGPS->DrawLine(bluePen, 447, 3, x, y);
	while (true) {
		route_plan^ B_point = gcnew route_plan(this, &boat::B_plan);
		this->Invoke(B_point, gcnew double(latB), (longB));
	}

}

private: void StopC() {
// route planning of C
// arduino control
	double latC = 22.6223; // the latitude of point C
	double longC = 120.2641; // the longitude of point C
	double x;
	double y;
	if (truelong >120.26385  && truelong < 120.2641) {
		if (truelat > 22.62224 && truelat < 22.62237) {
			x = 2980000 * (truelong - 120.26385);
			y = -3200000 * (truelat - 22.62237);
		}
	}
	Pen^ bluePen = gcnew Pen(Color::Blue, 3.0f);
	picGPS->DrawLine(bluePen, 745, 224, x, y);
	while (true) {
		route_plan^ C_point = gcnew route_plan(this, &boat::C_plan);
		this->Invoke(C_point, gcnew double(latC), (longC));
	}
}

private: void StopShortest() {
// route planning of nearest 
// arduino control
	double latA = 22.6223; // the latitude of point A
	double longA = 120.26385; // the longitude of point A 
	double latB = 22.62237; // the latitude of point B
	double longB = 120.2640; // the longitude of point B 
	double latC = 22.6223; // the latitude of point C
	double longC = 120.2641; // the longitude of point C
	while (true)
	{
		shortplan^ short_point = gcnew shortplan(this, &boat::short_plan);
		this->Invoke(short_point, gcnew double(latA), (longA), (latB), (longB), (latC), (longC));
	}

}

private: void A_plan(double deslat, double deslong) {  // A point
	if (direction2 != direction || dis2 != dis) {
		direction2 = direction;
		dis2 = dis;
	}
	direction = get_angle(truelat, truelong, deslat, deslong);
	dis = get_distance(truelat, truelong, deslat, deslong);
	
	int angle_diff = direction - direction2;
	double dis_diff = dis - dis2;

	if (angle_diff == direction || dis_diff == dis) {
		serialPort1->Write("f");
	}
	// 向下角度變大 向上角度變小 
	else {
		if (angle_diff < 0 && dis_diff < 0) { // angle increase and far away the destination
			serialPort1->Write("r"); // ignore the angle and turn right
			
		}
		///////////////////////////////
		else if (angle_diff < 0 && dis_diff > 0) { // angle increase and close to the destination
			if (dis > 151) {
				if (direction < 90 && direction > 0) {  // 45 degree
					if (direction < 38) {
						serialPort1->Write("l");
					}
					else if (direction > 52) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 180 && direction > 90) { // 135 degree
					if (direction < 128) {
						serialPort1->Write("l");
					}
					else if (direction> 142) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 270 && direction >180) { // 225 degree
					if (direction < 218) {
						serialPort1->Write("l");
					}
					else if (direction > 232) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 360 && direction > 270) { // 315 degree
					if (direction < 308) {
						serialPort1->Write("l");
					}
					else if (direction > 322) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
			}
			else if (dis < 150 && dis > 80) {
				serialPort1->Write("s");
			}
			else if (dis <= 79) {
				if (direction < 90 && direction > 0) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 180 && direction > 90) {
					serialPort1->Write("2"); // turn left
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 270 && direction >180) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 360 && direction > 270) {
					serialPort1->Write("2"); // turn left 
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}

			}
		}
		////////////////////////////////////
		else if (angle_diff > 0 && dis_diff < 0) { // angle decrease and far away the destination
			serialPort1->Write("l"); // ignore the angle and turn left
			
		}
		//////////////////////////////////////////
		else if (angle_diff > 0 && dis_diff > 0) {  // angle decrease and close to the destination
			if (dis > 151) {
				if (direction < 90 && direction > 0) {  // 45 degree
					if (direction < 38) {
						serialPort1->Write("l");
					}
					else if (direction > 52) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 180 && direction > 90) { // 135 degree
					if (direction < 128) {
						serialPort1->Write("l");
					}
					else if (direction> 142) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 270 && direction >180) { // 225 degree
					if (direction < 218) {
						serialPort1->Write("l");
					}
					else if (direction > 232) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 360 && direction > 270) { // 315 degree
					if (direction < 308) {
						serialPort1->Write("l");
					}
					else if (direction > 322) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
			}
			else if (dis < 150 && dis > 80) {
				serialPort1->Write("s");
			}
			else if (dis <= 79) {
				if (direction < 90 && direction > 0) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 180 && direction > 90) {
					serialPort1->Write("2"); // turn left
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 270 && direction >180) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 360 && direction > 270) {
					serialPort1->Write("2"); // turn left 
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}

			}
		}
	}

}

private: void B_plan(double deslat, double deslong) { //B point
	if (direction2 != direction || dis2 != dis) {
		direction2 = direction;
		dis2 = dis;
	}
	direction = get_angle(truelat, truelong, deslat, deslong);
	dis = get_distance(truelat, truelong, deslat, deslong);

	int angle_diff = direction - direction2;
	double dis_diff = dis - dis2;

	if (angle_diff == direction || dis_diff == dis) {
		serialPort1->Write("f");
	}
	else {
		if (angle_diff < 0 && dis_diff < 0) { // angle increase and far away the destination
			serialPort1->Write("r"); // ignore the angle and turn right
			
		}
		///////////////////////////////
		else if (angle_diff < 0 && dis_diff > 0) { // angle increase and close to the destination
			if (dis > 151) {
				if (direction < 90 && direction > 0) {  // 45 degree
					if (direction < 38) {
						serialPort1->Write("l");
					}
					else if (direction > 52) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 180 && direction > 90) { // 135 degree
					if (direction < 128) {
						serialPort1->Write("l");
					}
					else if (direction> 142) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 270 && direction >180) { // 225 degree
					if (direction < 218) {
						serialPort1->Write("l");
					}
					else if (direction > 232) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 360 && direction > 270) { // 315 degree
					if (direction < 308) {
						serialPort1->Write("l");
					}
					else if (direction > 322) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
			}
			else if (dis < 150 && dis > 80) {
				serialPort1->Write("s");
			}
			else if (dis <= 79) {
				if (direction < 90 && direction > 0) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 180 && direction > 90) {
					serialPort1->Write("2"); // turn left
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 270 && direction >180) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 360 && direction > 270) {
					serialPort1->Write("2"); // turn left 
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}

			}
		}
		////////////////////////////////////
		else if (angle_diff > 0 && dis_diff < 0) { // angle decrease and far away the destination
			serialPort1->Write("l"); // ignore the angle and turn left
		   
		}
		//////////////////////////////////////////
		else if (angle_diff > 0 && dis_diff > 0) {  // angle decrease and close to the destination
			if (dis > 151) {
				if (direction < 90 && direction > 0) {  // 45 degree
					if (direction < 38) {
						serialPort1->Write("l");
					}
					else if (direction > 52) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 180 && direction > 90) { // 135 degree
					if (direction < 128) {
						serialPort1->Write("l");
					}
					else if (direction> 142) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 270 && direction >180) { // 225 degree
					if (direction < 218) {
						serialPort1->Write("l");
					}
					else if (direction > 232) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 360 && direction > 270) { // 315 degree
					if (direction < 308) {
						serialPort1->Write("l");
					}
					else if (direction > 322) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
			}
			else if (dis < 150 && dis > 80) {
				serialPort1->Write("s");
			}
			else if (dis <= 79) {
				if (direction < 90 && direction > 0) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 180 && direction > 90) {
					serialPort1->Write("2"); // turn left
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 270 && direction >180) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 360 && direction > 270) {
					serialPort1->Write("2"); // turn left 
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}

			}
		}
	}

}

private: void C_plan(double deslat, double deslong) { // C point
	if (direction2 != direction || dis2 != dis) {
		direction2 = direction;
		dis2 = dis;
	}
	direction = get_angle(truelat, truelong, deslat, deslong);
	dis = get_distance(truelat, truelong, deslat, deslong);

	int angle_diff = direction - direction2;
	double dis_diff = dis - dis2;

	if (angle_diff == direction || dis_diff == dis) {
		serialPort1->Write("f");
	}
	else {
		if (angle_diff < 0 && dis_diff < 0) { // angle increase and far away the destination
			serialPort1->Write("r"); // ignore the angle and turn right
			
		}
		///////////////////////////////
		else if (angle_diff < 0 && dis_diff > 0) { // angle increase and close to the destination
			if (dis > 151) {
				if (direction < 90 && direction > 0) {  // 45 degree
					if (direction < 38) {
						serialPort1->Write("l");
					}
					else if (direction > 52) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 180 && direction > 90) { // 135 degree
					if (direction < 128) {
						serialPort1->Write("l");
					}
					else if (direction> 142) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 270 && direction >180) { // 225 degree
					if (direction < 218) {
						serialPort1->Write("l");
					}
					else if (direction > 232) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 360 && direction > 270) { // 315 degree
					if (direction < 308) {
						serialPort1->Write("l");
					}
					else if (direction > 322) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
			}
			else if (dis < 150 && dis > 80) {
				serialPort1->Write("s");
			}
			else if (dis <= 79) {
				if (direction < 90 && direction > 0) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 180 && direction > 90) {
					serialPort1->Write("2"); // turn left
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 270 && direction >180) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 360 && direction > 270) {
					serialPort1->Write("2"); // turn left 
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}

			}
		}
		////////////////////////////////////
		else if (angle_diff > 0 && dis_diff < 0) { // angle decrease and far away the destination
			serialPort1->Write("l"); // ignore the angle and turn left
	       
		}
		//////////////////////////////////////////
		else if (angle_diff > 0 && dis_diff > 0) {  // angle decrease and close to the destination
			if (dis > 151) {
				if (direction < 90 && direction > 0) {  // 45 degree
					if (direction < 38) {
						serialPort1->Write("l");
					}
					else if (direction > 52) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 180 && direction > 90) { // 135 degree
					if (direction < 128) {
						serialPort1->Write("l");
					}
					else if (direction> 142) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 270 && direction >180) { // 225 degree
					if (direction < 218) {
						serialPort1->Write("l");
					}
					else if (direction > 232) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
				else if (direction < 360 && direction > 270) { // 315 degree
					if (direction < 308) {
						serialPort1->Write("l");
					}
					else if (direction > 322) {
						serialPort1->Write("r");
					}
					else {
						serialPort1->Write("f");
					}
				}
			}
			else if (dis < 150 && dis > 80) {
				serialPort1->Write("s");
			}
			else if (dis <= 79) {
				if (direction < 90 && direction > 0) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 180 && direction > 90) {
					serialPort1->Write("2"); // turn left
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 270 && direction >180) {
					serialPort1->Write("0"); // turn right
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}
				else if (direction < 360 && direction > 270) {
					serialPort1->Write("2"); // turn left 
					if (dis = 0 || dis > 200) {
						serialPort1->Write("s");
					}
				}

			}
		}
	}


}

private: void short_plan(double latA, double longA, double latB, double longB, double latC, double longC) {
	double A_distance;
	double B_distance;
	double C_distance;

	if (judge_dis < 1) {
		double A_distance = get_distance(truelat, truelong, latA, longA);
		double B_distance = get_distance(truelat, truelong, latB, longB);
		double C_distance = get_distance(truelat, truelong, latC, longC);
		judge_dis = 1;
	}
	

	if (A_distance > B_distance && A_distance > C_distance) { // to A point
		if (direction2 != direction || dis2 != dis) {
			direction2 = direction;
			dis2 = dis;
		}
		direction = get_angle(truelat, truelong,latA, longA);
		dis = get_distance(truelat, truelong, latA, longA);

		int angle_diff = direction - direction2;
		double dis_diff = dis - dis2;

		if (angle_diff == direction || dis_diff == dis) {
			serialPort1->Write("f");
		}
		else {
			if (angle_diff < 0 && dis_diff < 0) { // angle increase and far away the destination
				serialPort1->Write("r"); // ignore the angle and turn right
			}
			///////////////////////////////
			else if (angle_diff < 0 && dis_diff > 0) { // angle increase and close to the destination
				if (dis > 151) {
					if (direction < 90 && direction > 0) {  // 45 degree
						if (direction < 38) {
							serialPort1->Write("l");
						}
						else if (direction > 52) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 180 && direction > 90) { // 135 degree
						if (direction < 128) {
							serialPort1->Write("l");
						}
						else if (direction> 142) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 270 && direction >180) { // 225 degree
						if (direction < 218) {
							serialPort1->Write("l");
						}
						else if (direction > 232) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 360 && direction > 270) { // 315 degree
						if (direction < 308) {
							serialPort1->Write("l");
						}
						else if (direction > 322) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
				}
				else if (dis < 150 && dis > 80) {
					serialPort1->Write("s");
				}
				else if (dis <= 79) {
					if (direction < 90 && direction > 0) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 180 && direction > 90) {
						serialPort1->Write("2"); // turn left
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 270 && direction >180) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 360 && direction > 270) {
						serialPort1->Write("2"); // turn left 
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}

				}
			}
			////////////////////////////////////
			else if (angle_diff > 0 && dis_diff < 0) { // angle decrease and far away the destination
				serialPort1->Write("l"); // ignore the angle and turn left
										
			}
			//////////////////////////////////////////
			else if (angle_diff > 0 && dis_diff > 0) {  // angle decrease and close to the destination
				if (dis > 151) {
					if (direction < 90 && direction > 0) {  // 45 degree
						if (direction < 38) {
							serialPort1->Write("l");
						}
						else if (direction > 52) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 180 && direction > 90) { // 135 degree
						if (direction < 128) {
							serialPort1->Write("l");
						}
						else if (direction> 142) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 270 && direction >180) { // 225 degree
						if (direction < 218) {
							serialPort1->Write("l");
						}
						else if (direction > 232) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 360 && direction > 270) { // 315 degree
						if (direction < 308) {
							serialPort1->Write("l");
						}
						else if (direction > 322) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
				}
				else if (dis < 150 && dis > 80) {
					serialPort1->Write("s");
				}
				else if (dis <= 79) {
					if (direction < 90 && direction > 0) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 180 && direction > 90) {
						serialPort1->Write("2"); // turn left
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 270 && direction >180) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 360 && direction > 270) {
						serialPort1->Write("2"); // turn left 
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}

				}
			}
		}
	}
	///////////////////////////////////////////////////
	else if (B_distance > A_distance && B_distance > C_distance) { // to B point
		if (direction2 != direction || dis2 != dis) {
			direction2 = direction;
			dis2 = dis;
		}
		direction = get_angle(truelat, truelong, latB, longB);
		dis = get_distance(truelat, truelong, latB, longB);

		int angle_diff = direction - direction2;
		double dis_diff = dis - dis2;

		if (angle_diff == direction || dis_diff == dis) {
			serialPort1->Write("f");
		}
		else {
			if (angle_diff < 0 && dis_diff < 0) { // angle increase and far away the destination
				serialPort1->Write("r"); // ignore the angle and turn right
			}
			///////////////////////////////
			else if (angle_diff < 0 && dis_diff > 0) { // angle increase and close to the destination
				if (dis > 151) {
					if (direction < 90 && direction > 0) {  // 45 degree
						if (direction < 38) {
							serialPort1->Write("l");
						}
						else if (direction > 52) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 180 && direction > 90) { // 135 degree
						if (direction < 128) {
							serialPort1->Write("l");
						}
						else if (direction> 142) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 270 && direction >180) { // 225 degree
						if (direction < 218) {
							serialPort1->Write("l");
						}
						else if (direction > 232) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 360 && direction > 270) { // 315 degree
						if (direction < 308) {
							serialPort1->Write("l");
						}
						else if (direction > 322) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
				}
				else if (dis < 150 && dis > 80) {
					serialPort1->Write("s");
				}
				else if (dis <= 79) {
					if (direction < 90 && direction > 0) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 180 && direction > 90) {
						serialPort1->Write("2"); // turn left
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 270 && direction >180) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 360 && direction > 270) {
						serialPort1->Write("2"); // turn left 
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}

				}
			}
			////////////////////////////////////
			else if (angle_diff > 0 && dis_diff < 0) { // angle decrease and far away the destination
				serialPort1->Write("l"); // ignore the angle and turn left

			}
			//////////////////////////////////////////
			else if (angle_diff > 0 && dis_diff > 0) {  // angle decrease and close to the destination
				if (dis > 151) {
					if (direction < 90 && direction > 0) {  // 45 degree
						if (direction < 38) {
							serialPort1->Write("l");
						}
						else if (direction > 52) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 180 && direction > 90) { // 135 degree
						if (direction < 128) {
							serialPort1->Write("l");
						}
						else if (direction> 142) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 270 && direction >180) { // 225 degree
						if (direction < 218) {
							serialPort1->Write("l");
						}
						else if (direction > 232) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 360 && direction > 270) { // 315 degree
						if (direction < 308) {
							serialPort1->Write("l");
						}
						else if (direction > 322) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
				}
				else if (dis < 150 && dis > 80) {
					serialPort1->Write("s");
				}
				else if (dis <= 79) {
					if (direction < 90 && direction > 0) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 180 && direction > 90) {
						serialPort1->Write("2"); // turn left
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 270 && direction >180) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 360 && direction > 270) {
						serialPort1->Write("2"); // turn left 
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}

				}
			}
		}
	}
	////////////////////////////////////////////////////////
	else if (C_distance > A_distance && C_distance > B_distance) { // to C point
		if (direction2 != direction || dis2 != dis) {
			direction2 = direction;
			dis2 = dis;
		}
		direction = get_angle(truelat, truelong, latC, longC);
		dis = get_distance(truelat, truelong, latC, longC);

		int angle_diff = direction - direction2;
		double dis_diff = dis - dis2;

		if (angle_diff == direction || dis_diff == dis) {
			serialPort1->Write("f");
		}
		else {
			if (angle_diff < 0 && dis_diff < 0) { // angle increase and far away the destination
				serialPort1->Write("r"); // ignore the angle and turn right
			}
			///////////////////////////////
			else if (angle_diff < 0 && dis_diff > 0) { // angle increase and close to the destination
				if (dis > 151) {
					if (direction < 90 && direction > 0) {  // 45 degree
						if (direction < 38) {
							serialPort1->Write("l");
						}
						else if (direction > 52) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 180 && direction > 90) { // 135 degree
						if (direction < 128) {
							serialPort1->Write("l");
						}
						else if (direction> 142) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 270 && direction >180) { // 225 degree
						if (direction < 218) {
							serialPort1->Write("l");
						}
						else if (direction > 232) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 360 && direction > 270) { // 315 degree
						if (direction < 308) {
							serialPort1->Write("l");
						}
						else if (direction > 322) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
				}
				else if (dis < 150 && dis > 80) {
					serialPort1->Write("s");
				}
				else if (dis <= 79) {
					if (direction < 90 && direction > 0) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 180 && direction > 90) {
						serialPort1->Write("2"); // turn left
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 270 && direction >180) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 360 && direction > 270) {
						serialPort1->Write("2"); // turn left 
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}

				}
			}
			////////////////////////////////////
			else if (angle_diff > 0 && dis_diff < 0) { // angle decrease and far away the destination
				serialPort1->Write("l"); // ignore the angle and turn left

			}
			//////////////////////////////////////////
			else if (angle_diff > 0 && dis_diff > 0) {  // angle decrease and close to the destination
				if (dis > 151) {
					if (direction < 90 && direction > 0) {  // 45 degree
						if (direction < 38) {
							serialPort1->Write("l");
						}
						else if (direction > 52) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 180 && direction > 90) { // 135 degree
						if (direction < 128) {
							serialPort1->Write("l");
						}
						else if (direction> 142) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 270 && direction >180) { // 225 degree
						if (direction < 218) {
							serialPort1->Write("l");
						}
						else if (direction > 232) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
					else if (direction < 360 && direction > 270) { // 315 degree
						if (direction < 308) {
							serialPort1->Write("l");
						}
						else if (direction > 322) {
							serialPort1->Write("r");
						}
						else {
							serialPort1->Write("f");
						}
					}
				}
				else if (dis < 150 && dis > 80) {
					serialPort1->Write("s");
				}
				else if (dis <= 79) {
					if (direction < 90 && direction > 0) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 180 && direction > 90) {
						serialPort1->Write("2"); // turn left
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 270 && direction >180) {
						serialPort1->Write("0"); // turn right
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}
					else if (direction < 360 && direction > 270) {
						serialPort1->Write("2"); // turn left 
						if (dis = 0 || dis > 200) {
							serialPort1->Write("s");
						}
					}

				}
			}
		}
	}


}

};
}
