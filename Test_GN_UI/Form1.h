#pragma once

#include <stdlib.h>
#include <time.h> 
#include <msclr\marshal_cppstd.h>
#include "NetworkGeneticAlgorithm.h"
#include "Visualizator.h"

const int MIN_ALLELE_COUNT = 2;
const int MAX_ALLELE_COUNT = 4;

namespace Test_GN_UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Drawing::Drawing2D;
	using namespace Microsoft::Msagl::Drawing;



	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();

			//
			//TODO: добавьте код конструктора
			//

			testNet = new Network();
			population = new NetworkPopulation(0, "NA");
			gnet = new NetworkGeneticAlgorithm();
			vis = new Visualizator();
			/*
			(*population).setNet(*testNet);
			(*gnet).setPopulation(*population);
			(*gnet).createPopulation(*description, POPULATION_SIZE);
			(*gnet).gaFitness(*description);*/

			toolTip2->SetToolTip(textBox1, "Размер популяции");
			toolTip2->SetToolTip(textBox2, "Число потомков");
			toolTip2->SetToolTip(textBox3, "Число отбираемых особей");

			richTextBox1->AppendText("LOG\n\n");
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;




	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


		Network *testNet;
		NetworkPopulation *population;
		NetworkDescription *description;
		NetworkGeneticAlgorithm *gnet;
		Visualizator *vis;

		String^ STORAGE_NAME;
		String^ NET_NAME;

		int POPULATION_SIZE;
		int GENERATION = 0;
		int EVOLUTION_COUNT = 20;
		double MUTATION = 0.5;

		int SELECTION_COUNT = 20;
		int MAX_PRICE = 50;

	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ToolTip^  toolTip2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  statButton;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->statButton = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(826, 502);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->richTextBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(818, 476);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Общее";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Location = System::Drawing::Point(28, 274);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(357, 157);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Настройки генетического алгоритма";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(28, 118);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(144, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox3_KeyUp);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(28, 81);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(144, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox2_KeyUp);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(28, 43);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(144, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox1_KeyUp);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(189, 41);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(113, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Задать популяцию";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(481, 53);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(295, 105);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Настройки сети";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(36, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(234, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Загрузить топологию сети";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(36, 60);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(234, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Загрузить доступное оборудование";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(517, 198);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(234, 40);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Эволюция";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(28, 53);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(420, 185);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->statButton);
			this->tabPage2->Controls->Add(this->chart1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(818, 476);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Статистика";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// statButton
			// 
			this->statButton->Location = System::Drawing::Point(572, 77);
			this->statButton->Name = L"statButton";
			this->statButton->Size = System::Drawing::Size(156, 40);
			this->statButton->TabIndex = 1;
			this->statButton->Text = L"Показать статистику";
			this->statButton->UseVisualStyleBackColor = true;
			this->statButton->Click += gcnew System::EventHandler(this, &Form1::statButton_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(39, 56);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(414, 311);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button5);
			this->tabPage3->Controls->Add(this->pictureBox1);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(818, 476);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Визуализация сети";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(592, 54);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(149, 24);
			this->button5->TabIndex = 1;
			this->button5->Text = L"test";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Location = System::Drawing::Point(33, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(485, 332);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// toolTip2
			// 
			this->toolTip2->AutoPopDelay = 5000;
			this->toolTip2->InitialDelay = 100;
			this->toolTip2->IsBalloon = true;
			this->toolTip2->ReshowDelay = 100;
			this->toolTip2->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &Form1::toolTip2_Popup);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 526);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog openFileDialog;// = gcnew OpenFileDialog;
		openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";

		if (openFileDialog.ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			NET_NAME = openFileDialog.FileName;
			(*testNet).loadFromFile(msclr::interop::marshal_as<std::string>(openFileDialog.FileName));
			(*population).setNet(*testNet);

			richTextBox1->AppendText("Network uploaded. (Platform count = "+(*testNet).getPlatformCount() + ")\n");
		}

	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog openFileDialog;// = gcnew OpenFileDialog;
		openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";

		if (openFileDialog.ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			STORAGE_NAME = openFileDialog.FileName;
			(*population).fillStorage(msclr::interop::marshal_as<std::string>(openFileDialog.FileName));

			description = new NetworkDescription(MIN_ALLELE_COUNT, MAX_ALLELE_COUNT, (*population).getStorage());
			(*gnet).setPopulation(*population);
			richTextBox1->AppendText("Storage are filled\n");
		}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		POPULATION_SIZE = System::Convert::ToInt32(textBox1->Text);

		(*gnet).createPopulation(*description, POPULATION_SIZE);

		(*gnet).gaFitness(*description);

		richTextBox1->AppendText("Create Population (POPULATION_SIZE = " + POPULATION_SIZE + ")\n");

}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	richTextBox1->AppendText(gcnew String("Generation " + GENERATION + "\n"));

	(*gnet).gaEvolution(EVOLUTION_COUNT, MUTATION, *description);
	(*gnet).gaFitness(*description);

	(*gnet).gaSelection(SELECTION_COUNT, MAX_PRICE);
	richTextBox1->AppendText(gcnew String((*gnet).gaShowBest(*description).c_str()));
	richTextBox1->AppendText("\n");

	GENERATION++;
}

private: System::Void textBox1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Enter)
	{
		POPULATION_SIZE = System::Convert::ToInt32(textBox1->Text);
	}
}
private: System::Void textBox2_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Enter)
	{
		EVOLUTION_COUNT = System::Convert::ToInt32(textBox2->Text);
		richTextBox1->AppendText("EVOLUTION_COUNT = " + EVOLUTION_COUNT + "\n");
	}
}
private: System::Void textBox3_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Enter)
	{
		SELECTION_COUNT = System::Convert::ToInt32(textBox3->Text);
		richTextBox1->AppendText("SELECTION_COUNT = " + SELECTION_COUNT + "\n");
	}
}
private: System::Void toolTip2_Popup(System::Object^  sender, System::Windows::Forms::PopupEventArgs^  e) {
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	Microsoft::Msagl::GraphViewerGdi::GViewer^ viewer = gcnew Microsoft::Msagl::GraphViewerGdi::GViewer();
	/*
	// create the graph content
	graph->AddEdge("A", "B");
	graph->AddEdge("B", "C");
	graph->AddEdge("A", "C");*/

	Microsoft::Msagl::Drawing::Graph^ graph = vis->viewBestGenome(gnet, *description);

	viewer->Graph = graph;
	pictureBox1->SuspendLayout();
	viewer->Dock = System::Windows::Forms::DockStyle::Fill;
	pictureBox1->Controls->Add(viewer);
	pictureBox1->ResumeLayout();
}
private: System::Void statButton_Click(System::Object^  sender, System::EventArgs^  e) {
	ChartArea ^chartArea = gcnew ChartArea();
	//Область в которой будет построен график (их может быть несколько)
	chartArea->Name = "chartArea";
	chart1->ChartAreas->Add(chartArea);
	// График (их может быть несколько)

	System::Collections::Generic::Dictionary <int, int>^ d = vis->viewChart(population);

	Series ^series1 = gcnew Series();
	series1->ChartType = SeriesChartType::Line;
	series1->MarkerStyle = MarkerStyle::Circle;
	series1->ChartArea = "chartArea";


	series1->Points->DataBindXY(d->Keys, d->Values);
	series1->Color = System::Drawing::Color::Green;
	series1->BorderWidth = 2;

	series1->IsValueShownAsLabel = true;

	chart1->Series->Add(series1); 
	//chart1->ResumeLayout();
}
};
}
