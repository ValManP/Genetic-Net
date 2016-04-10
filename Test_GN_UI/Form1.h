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
	using namespace System::Collections::ObjectModel;
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

			series = gcnew Collection<Series^>();

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
		GACrossover<NetworkGenome, NetworkDescription> *crossover;
		GAMutation<NetworkGenome, NetworkDescription> *mutation;
		GASelection<NetworkPopulation> *selection;
		GAFitness<NetworkPopulation, NetworkDescription> *fitness;
		GACrossbreeding<NetworkPopulation, NetworkGenome> *crossbreeding;
		GAReproductionScheme<NetworkPopulation> *reproductionScheme;
		Visualizator *vis;

		String^ STORAGE_NAME;
		String^ NET_NAME;

		Collection<Series^>^ series;

		int POPULATION_SIZE;
		int GENERATION = 0;
		int EVOLUTION_COUNT = 20;
		double MUTATION = 0.01;
		int MUTATION_COUNT = 10;

		int SELECTION_COUNT = 20;
		double SELECTION_VARIABLE = 1;
		double CROSSBREEDING_VARIABLE = 1;
		double REPRODUCTION_VARIABLE = 1;
		int MAX_PRICE = 50;

	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox_EVOLUTION_COUNT;
	private: System::Windows::Forms::TextBox^  textBox_SELECTION_COUNT;


	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ToolTip^  toolTip2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::Label^  label_EVOLUTION_COUNT;
	private: System::Windows::Forms::Label^  label_SELECTION_COUNT;
	private: System::Windows::Forms::CheckBox^  checkBox2_show_all;
	private: System::Windows::Forms::ComboBox^  generationViewComboBox;
	private: System::Windows::Forms::Button^  viewNetButton;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  mutationComboBox;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  selectionTypeComboBox;


	private: System::Windows::Forms::Label^  crossoverType;
	private: System::Windows::Forms::ComboBox^  crossoverTypeComboBox;
	private: System::Windows::Forms::Label^  parentChoiceType;
	private: System::Windows::Forms::ComboBox^  parentChoiceComboBox;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::TextBox^  mutationProbabilityTextBox;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::TextBox^  mutationCountTextBox;

private: System::Windows::Forms::TextBox^  selectionVariableTextBox;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::ComboBox^  fitnessFunctionComboBox;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::ComboBox^  reproductionSchemeComboBox;
private: System::Windows::Forms::TextBox^  crossbreedingTextBox;
private: System::Windows::Forms::TextBox^  reproductionSchemeTextBox;






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
			this->reproductionSchemeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->crossbreedingTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->reproductionSchemeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->fitnessFunctionComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->selectionVariableTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->mutationProbabilityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mutationCountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->mutationComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->selectionTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->crossoverType = (gcnew System::Windows::Forms::Label());
			this->crossoverTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->parentChoiceType = (gcnew System::Windows::Forms::Label());
			this->parentChoiceComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label_SELECTION_COUNT = (gcnew System::Windows::Forms::Label());
			this->label_EVOLUTION_COUNT = (gcnew System::Windows::Forms::Label());
			this->textBox_SELECTION_COUNT = (gcnew System::Windows::Forms::TextBox());
			this->textBox_EVOLUTION_COUNT = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->generationViewComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox2_show_all = (gcnew System::Windows::Forms::CheckBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->viewNetButton = (gcnew System::Windows::Forms::Button());
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
			this->tabControl1->Size = System::Drawing::Size(828, 569);
			this->tabControl1->TabIndex = 0;
			this->tabControl1->Selecting += gcnew System::Windows::Forms::TabControlCancelEventHandler(this, &Form1::tabControl1_Selecting);
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
			this->tabPage1->Size = System::Drawing::Size(820, 543);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Общее";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->reproductionSchemeTextBox);
			this->groupBox2->Controls->Add(this->crossbreedingTextBox);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->reproductionSchemeComboBox);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->fitnessFunctionComboBox);
			this->groupBox2->Controls->Add(this->selectionVariableTextBox);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->mutationProbabilityTextBox);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->mutationCountTextBox);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->mutationComboBox);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->selectionTypeComboBox);
			this->groupBox2->Controls->Add(this->crossoverType);
			this->groupBox2->Controls->Add(this->crossoverTypeComboBox);
			this->groupBox2->Controls->Add(this->parentChoiceType);
			this->groupBox2->Controls->Add(this->parentChoiceComboBox);
			this->groupBox2->Controls->Add(this->label_SELECTION_COUNT);
			this->groupBox2->Controls->Add(this->label_EVOLUTION_COUNT);
			this->groupBox2->Controls->Add(this->textBox_SELECTION_COUNT);
			this->groupBox2->Controls->Add(this->textBox_EVOLUTION_COUNT);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Location = System::Drawing::Point(28, 232);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(770, 305);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Настройки генетического алгоритма";
			// 
			// reproductionSchemeTextBox
			// 
			this->reproductionSchemeTextBox->Location = System::Drawing::Point(563, 189);
			this->reproductionSchemeTextBox->Name = L"reproductionSchemeTextBox";
			this->reproductionSchemeTextBox->Size = System::Drawing::Size(37, 20);
			this->reproductionSchemeTextBox->TabIndex = 28;
			this->toolTip2->SetToolTip(this->reproductionSchemeTextBox, L"Для ввода нажмите Пробел");
			this->reproductionSchemeTextBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::reproductionSchemeTextBox_KeyUp);
			// 
			// crossbreedingTextBox
			// 
			this->crossbreedingTextBox->Location = System::Drawing::Point(185, 149);
			this->crossbreedingTextBox->Name = L"crossbreedingTextBox";
			this->crossbreedingTextBox->Size = System::Drawing::Size(37, 20);
			this->crossbreedingTextBox->TabIndex = 27;
			this->toolTip2->SetToolTip(this->crossbreedingTextBox, L"Для ввода нажмите Пробел");
			this->crossbreedingTextBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::crossbreedingTextBox_KeyUp);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(618, 192);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(107, 13);
			this->label6->TabIndex = 26;
			this->label6->Text = L"Схема репродукции";
			// 
			// reproductionSchemeComboBox
			// 
			this->reproductionSchemeComboBox->FormattingEnabled = true;
			this->reproductionSchemeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Поколенческая репродукция" });
			this->reproductionSchemeComboBox->Location = System::Drawing::Point(401, 189);
			this->reproductionSchemeComboBox->Name = L"reproductionSchemeComboBox";
			this->reproductionSchemeComboBox->Size = System::Drawing::Size(144, 21);
			this->reproductionSchemeComboBox->TabIndex = 25;
			this->reproductionSchemeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::reproductionSchemeComboBox_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(618, 152);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(112, 13);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Тип фитнес-функции";
			// 
			// fitnessFunctionComboBox
			// 
			this->fitnessFunctionComboBox->FormattingEnabled = true;
			this->fitnessFunctionComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Ф-Ф со случайными весами" });
			this->fitnessFunctionComboBox->Location = System::Drawing::Point(401, 149);
			this->fitnessFunctionComboBox->Name = L"fitnessFunctionComboBox";
			this->fitnessFunctionComboBox->Size = System::Drawing::Size(144, 21);
			this->fitnessFunctionComboBox->TabIndex = 23;
			this->fitnessFunctionComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::fitnessFunctionComboBox_SelectedIndexChanged);
			// 
			// selectionVariableTextBox
			// 
			this->selectionVariableTextBox->Location = System::Drawing::Point(185, 227);
			this->selectionVariableTextBox->Name = L"selectionVariableTextBox";
			this->selectionVariableTextBox->Size = System::Drawing::Size(37, 20);
			this->selectionVariableTextBox->TabIndex = 21;
			this->toolTip2->SetToolTip(this->selectionVariableTextBox, L"Для ввода нажмите Пробел");
			this->selectionVariableTextBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::selectionVariableTextBox_KeyUp);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(618, 114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(117, 13);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Вероятность мутации";
			// 
			// mutationProbabilityTextBox
			// 
			this->mutationProbabilityTextBox->Location = System::Drawing::Point(401, 111);
			this->mutationProbabilityTextBox->Name = L"mutationProbabilityTextBox";
			this->mutationProbabilityTextBox->Size = System::Drawing::Size(144, 20);
			this->mutationProbabilityTextBox->TabIndex = 19;
			this->toolTip2->SetToolTip(this->mutationProbabilityTextBox, L"Для ввода нажмите Пробел");
			this->mutationProbabilityTextBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::mutationProbabilityTextBox_KeyUp);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(241, 114);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Число мутаций";
			// 
			// mutationCountTextBox
			// 
			this->mutationCountTextBox->Location = System::Drawing::Point(23, 111);
			this->mutationCountTextBox->Name = L"mutationCountTextBox";
			this->mutationCountTextBox->Size = System::Drawing::Size(144, 20);
			this->mutationCountTextBox->TabIndex = 17;
			this->toolTip2->SetToolTip(this->mutationCountTextBox, L"Для ввода нажмите Пробел");
			this->mutationCountTextBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::mutationCountTextBox_KeyUp);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(241, 267);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Тип мутации";
			// 
			// mutationComboBox
			// 
			this->mutationComboBox->FormattingEnabled = true;
			this->mutationComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Дополнение" });
			this->mutationComboBox->Location = System::Drawing::Point(23, 264);
			this->mutationComboBox->Name = L"mutationComboBox";
			this->mutationComboBox->Size = System::Drawing::Size(144, 21);
			this->mutationComboBox->TabIndex = 15;
			this->mutationComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::mutationComboBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(241, 230);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Тип селекции";
			// 
			// selectionTypeComboBox
			// 
			this->selectionTypeComboBox->FormattingEnabled = true;
			this->selectionTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"B-Турнирная селекция" });
			this->selectionTypeComboBox->Location = System::Drawing::Point(23, 227);
			this->selectionTypeComboBox->Name = L"selectionTypeComboBox";
			this->selectionTypeComboBox->Size = System::Drawing::Size(144, 21);
			this->selectionTypeComboBox->TabIndex = 13;
			this->selectionTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::selectionTypeComboBox_SelectedIndexChanged);
			// 
			// crossoverType
			// 
			this->crossoverType->AutoSize = true;
			this->crossoverType->Location = System::Drawing::Point(241, 192);
			this->crossoverType->Name = L"crossoverType";
			this->crossoverType->Size = System::Drawing::Size(89, 13);
			this->crossoverType->TabIndex = 12;
			this->crossoverType->Text = L"Тип кроссовера";
			// 
			// crossoverTypeComboBox
			// 
			this->crossoverTypeComboBox->FormattingEnabled = true;
			this->crossoverTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Одноточечный кроссовер", L"Однородный кроссовер" });
			this->crossoverTypeComboBox->Location = System::Drawing::Point(23, 189);
			this->crossoverTypeComboBox->Name = L"crossoverTypeComboBox";
			this->crossoverTypeComboBox->Size = System::Drawing::Size(144, 21);
			this->crossoverTypeComboBox->TabIndex = 11;
			this->crossoverTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::crossoverTypeComboBox_SelectedIndexChanged);
			// 
			// parentChoiceType
			// 
			this->parentChoiceType->AutoSize = true;
			this->parentChoiceType->Location = System::Drawing::Point(241, 152);
			this->parentChoiceType->Name = L"parentChoiceType";
			this->parentChoiceType->Size = System::Drawing::Size(128, 13);
			this->parentChoiceType->TabIndex = 10;
			this->parentChoiceType->Text = L"Оператор скрещивания";
			// 
			// parentChoiceComboBox
			// 
			this->parentChoiceComboBox->FormattingEnabled = true;
			this->parentChoiceComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Панмиксия", L"Инбридинг", L"Аутбридинг",
					L"Положительное ассоциативное скрещивание"
			});
			this->parentChoiceComboBox->Location = System::Drawing::Point(23, 149);
			this->parentChoiceComboBox->Name = L"parentChoiceComboBox";
			this->parentChoiceComboBox->Size = System::Drawing::Size(144, 21);
			this->parentChoiceComboBox->TabIndex = 9;
			this->parentChoiceComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::parentChoiceComboBox_SelectedIndexChanged);
			// 
			// label_SELECTION_COUNT
			// 
			this->label_SELECTION_COUNT->AutoSize = true;
			this->label_SELECTION_COUNT->Location = System::Drawing::Point(618, 76);
			this->label_SELECTION_COUNT->Name = L"label_SELECTION_COUNT";
			this->label_SELECTION_COUNT->Size = System::Drawing::Size(143, 13);
			this->label_SELECTION_COUNT->TabIndex = 8;
			this->label_SELECTION_COUNT->Text = L"Число отбираемых особей";
			// 
			// label_EVOLUTION_COUNT
			// 
			this->label_EVOLUTION_COUNT->AutoSize = true;
			this->label_EVOLUTION_COUNT->Location = System::Drawing::Point(241, 76);
			this->label_EVOLUTION_COUNT->Name = L"label_EVOLUTION_COUNT";
			this->label_EVOLUTION_COUNT->Size = System::Drawing::Size(115, 13);
			this->label_EVOLUTION_COUNT->TabIndex = 7;
			this->label_EVOLUTION_COUNT->Text = L"Число \"брачных пар\"";
			// 
			// textBox_SELECTION_COUNT
			// 
			this->textBox_SELECTION_COUNT->Location = System::Drawing::Point(401, 73);
			this->textBox_SELECTION_COUNT->Name = L"textBox_SELECTION_COUNT";
			this->textBox_SELECTION_COUNT->Size = System::Drawing::Size(144, 20);
			this->textBox_SELECTION_COUNT->TabIndex = 6;
			this->textBox_SELECTION_COUNT->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox3_KeyUp);
			// 
			// textBox_EVOLUTION_COUNT
			// 
			this->textBox_EVOLUTION_COUNT->Location = System::Drawing::Point(23, 73);
			this->textBox_EVOLUTION_COUNT->Name = L"textBox_EVOLUTION_COUNT";
			this->textBox_EVOLUTION_COUNT->Size = System::Drawing::Size(144, 20);
			this->textBox_EVOLUTION_COUNT->TabIndex = 5;
			this->toolTip2->SetToolTip(this->textBox_EVOLUTION_COUNT, L"Для ввода нажмите Пробел");
			this->textBox_EVOLUTION_COUNT->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox2_KeyUp);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(23, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(144, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox1_KeyUp);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(244, 35);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(138, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Задать популяцию";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(483, 23);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(315, 105);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Настройки сети";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(46, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(234, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Загрузить топологию сети";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(46, 60);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(234, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Загрузить доступное оборудование";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(529, 155);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(234, 40);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Эволюция";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(28, 23);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(420, 185);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->generationViewComboBox);
			this->tabPage2->Controls->Add(this->checkBox2_show_all);
			this->tabPage2->Controls->Add(this->chart1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(820, 543);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Статистика";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// generationViewComboBox
			// 
			this->generationViewComboBox->FormattingEnabled = true;
			this->generationViewComboBox->Location = System::Drawing::Point(578, 106);
			this->generationViewComboBox->Name = L"generationViewComboBox";
			this->generationViewComboBox->Size = System::Drawing::Size(153, 21);
			this->generationViewComboBox->TabIndex = 4;
			this->generationViewComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// checkBox2_show_all
			// 
			this->checkBox2_show_all->AutoSize = true;
			this->checkBox2_show_all->Location = System::Drawing::Point(578, 69);
			this->checkBox2_show_all->Name = L"checkBox2_show_all";
			this->checkBox2_show_all->Size = System::Drawing::Size(153, 17);
			this->checkBox2_show_all->TabIndex = 3;
			this->checkBox2_show_all->Text = L"Показать все поколения";
			this->checkBox2_show_all->UseVisualStyleBackColor = true;
			this->checkBox2_show_all->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_show_all_CheckedChanged);
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
			this->tabPage3->Controls->Add(this->viewNetButton);
			this->tabPage3->Controls->Add(this->button5);
			this->tabPage3->Controls->Add(this->pictureBox1);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(820, 543);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Визуализация сети";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// viewNetButton
			// 
			this->viewNetButton->Location = System::Drawing::Point(593, 88);
			this->viewNetButton->Name = L"viewNetButton";
			this->viewNetButton->Size = System::Drawing::Size(149, 24);
			this->viewNetButton->TabIndex = 2;
			this->viewNetButton->Text = L"Показать сеть";
			this->viewNetButton->UseVisualStyleBackColor = true;
			this->viewNetButton->Click += gcnew System::EventHandler(this, &Form1::viewNetButton_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(593, 35);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(149, 24);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Показать лучшую особь";
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
			this->ClientSize = System::Drawing::Size(853, 593);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
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
			testNet->loadFromFile(msclr::interop::marshal_as<std::string>(openFileDialog.FileName));
			population->setNet(*testNet);

			richTextBox1->AppendText("Network uploaded. (Platform count = "+(*testNet).getPlatformCount() + ")\n");
		}

	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog openFileDialog;// = gcnew OpenFileDialog;
		openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";

		if (openFileDialog.ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			STORAGE_NAME = openFileDialog.FileName;
			population->fillStorage(msclr::interop::marshal_as<std::string>(openFileDialog.FileName));

			description = new NetworkDescription(MIN_ALLELE_COUNT, MAX_ALLELE_COUNT, population->getStorage());
			gnet->setPopulation(population);
			richTextBox1->AppendText("Storage are filled\n");
		}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		POPULATION_SIZE = System::Convert::ToInt32(textBox1->Text);

		gnet->gaCreatePopulation(*description, POPULATION_SIZE);

		gnet->gaFitness(*description);

		series->Add(vis->getFillSeries(gnet->getPopulation(), GENERATION));

		richTextBox1->AppendText("Create Population (POPULATION_SIZE = " + POPULATION_SIZE + ")\n");
		generationViewComboBox->Items->Add("Generation " + GENERATION);

}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	GENERATION++;
	richTextBox1->AppendText(gcnew String("Generation " + GENERATION + "\n"));

	// Genetic Algoritm
	gnet->gaCrossbreeding(*description);
	gnet->gaFitness(*description);
	gnet->gaSelection(SELECTION_COUNT);

	richTextBox1->AppendText(gcnew String((*gnet).gaShowBest(*description).c_str()));
	richTextBox1->AppendText("\n");

	series->Add(vis->getFillSeries(gnet->getPopulation(), GENERATION));
	generationViewComboBox->Items->Add("Generation " + GENERATION);
}

private: System::Void textBox1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Space)
	{
		POPULATION_SIZE = System::Convert::ToInt32(textBox1->Text);
	}
}
private: System::Void textBox2_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Space)
	{
		EVOLUTION_COUNT = System::Convert::ToInt32(textBox_EVOLUTION_COUNT->Text);
		gnet->setCoupleCount(EVOLUTION_COUNT);
		richTextBox1->AppendText("EVOLUTION_COUNT = " + EVOLUTION_COUNT + "\n");
	}
}
private: System::Void textBox3_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Space)
	{
		SELECTION_COUNT = System::Convert::ToInt32(textBox_SELECTION_COUNT->Text);
		richTextBox1->AppendText("SELECTION_COUNT = " + SELECTION_COUNT + "\n");
	}
}
private: System::Void toolTip2_Popup(System::Object^  sender, System::Windows::Forms::PopupEventArgs^  e) {
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	Microsoft::Msagl::GraphViewerGdi::GViewer^ viewer = gcnew Microsoft::Msagl::GraphViewerGdi::GViewer();

	Microsoft::Msagl::Drawing::Graph^ graph = vis->viewBestGenome(gnet, *description);

	viewer->Graph = graph;
	pictureBox1->SuspendLayout();
	viewer->Dock = System::Windows::Forms::DockStyle::Fill;
	pictureBox1->Controls->Clear();
	pictureBox1->Controls->Add(viewer);
	pictureBox1->ResumeLayout();
}
private: System::Void statButton_Click(System::Object^  sender, System::EventArgs^  e) {

	chart1->ChartAreas->Clear();
	ChartArea^ area = gcnew ChartArea("Generation " + GENERATION);
	area->AxisX->Title = "Capacity";
	area->AxisY->Title = "Price";
	area->Name = "Generation " + GENERATION;
	chart1->ChartAreas->Add(area);

	chart1->Series->Clear();
	series[GENERATION]->ChartArea = "Generation " + GENERATION;
	chart1->Series->Add(series[GENERATION]);
}

private: System::Void checkBox2_show_all_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (checkBox2_show_all->Checked) {
		chart1->ChartAreas->Clear();
		ChartArea^ area = gcnew ChartArea("ALL");
		area->AxisX->Title = "Capacity";
		area->AxisY->Title = "Price";
		chart1->ChartAreas->Add(area);

		chart1->Series->Clear();
		series[GENERATION]->ChartArea = "Generation " + GENERATION;

		for (int i = 0; i < GENERATION + 1; i++) {
			series[i]->Color = Drawing::Color::FromArgb((rand() * i) % 256, (rand() * i) % 256, (rand() * i) % 256);
			series[i]->ChartArea = "ALL";
			//series[i]->LegendText = "Generation " + GENERATION;
			chart1->Series->Add(series[i]);
		}
	}
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	chart1->ChartAreas->Clear();
	ChartArea^ area = gcnew ChartArea("Generation " + GENERATION);
	area->AxisX->Title = "Capacity";
	area->AxisY->Title = "Price";
	area->Name = "Generation " + generationViewComboBox->SelectedIndex;
	chart1->ChartAreas->Add(area);

	chart1->Series->Clear();
	series[generationViewComboBox->SelectedIndex]->ChartArea = "Generation " + generationViewComboBox->SelectedIndex;
	chart1->Series->Add(series[generationViewComboBox->SelectedIndex]);
}
private: System::Void tabControl1_Selecting(System::Object^  sender, System::Windows::Forms::TabControlCancelEventArgs^  e) {
	if (POPULATION_SIZE != NULL) {
		chart1->ChartAreas->Clear();
		ChartArea^ area = gcnew ChartArea("Generation " + GENERATION);
		area->AxisX->Title = "Capacity";
		area->AxisY->Title = "Price";
		area->Name = "Generation " + GENERATION;
		chart1->ChartAreas->Add(area);

		chart1->Series->Clear();
		series[GENERATION]->ChartArea = "Generation " + GENERATION;
		chart1->Series->Add(series[GENERATION]);
	}
}

private: System::Void viewNetButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Microsoft::Msagl::GraphViewerGdi::GViewer^ viewer = gcnew Microsoft::Msagl::GraphViewerGdi::GViewer();

	Microsoft::Msagl::Drawing::Graph^ graph = vis->viewNetwork((*gnet).getPopulation().getNet());

	viewer->Graph = graph;
	pictureBox1->SuspendLayout();
	viewer->Dock = System::Windows::Forms::DockStyle::Fill;
	pictureBox1->Controls->Clear();
	pictureBox1->Controls->Add(viewer);
	pictureBox1->ResumeLayout();

}
private: System::Void crossoverTypeComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {



	switch (crossoverTypeComboBox->SelectedIndex)
	{
		case 0: {
			crossover = new SinglePointCrossover();
			gnet->setCrossoverOperator(crossover);
			break;
		}

		case 1: {
			crossover = new UniformCrossover();
			gnet->setCrossoverOperator(crossover);
			break;
		}


	default:
		break;
	}

}
private: System::Void mutationComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	switch (mutationComboBox->SelectedIndex)
	{
	case 0: {
		mutation = new FlipBitMutation();
		gnet->setMutationOperator(mutation);
		break;
	}


	default:
		break;
	}
}
private: System::Void mutationCountTextBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Space)
	{
		MUTATION_COUNT = System::Convert::ToInt32(mutationCountTextBox->Text);
		gnet->setMutationCount(MUTATION_COUNT);
		richTextBox1->AppendText("MUTATION_COUNT = " + MUTATION_COUNT + "\n");
	}
}
private: System::Void mutationProbabilityTextBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Space)
	{
		MUTATION = System::Convert::ToDouble(mutationProbabilityTextBox->Text);
		gnet->setMutationProbability(MUTATION);
		richTextBox1->AppendText("MUTATION = " + MUTATION + "\n");
	}
}
private: System::Void selectionVariableTextBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Space)
	{
		SELECTION_VARIABLE = System::Convert::ToInt32(selectionVariableTextBox->Text);
		gnet->setMutationProbability(SELECTION_VARIABLE);
		richTextBox1->AppendText("SELECTION_VARIABLE = " + SELECTION_VARIABLE + "\n");
	}
}
private: System::Void selectionTypeComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	switch (selectionTypeComboBox->SelectedIndex)
	{
	case 0: {
		selection = new B_TournamentSelection(SELECTION_VARIABLE);
		gnet->setSelectionOperator(selection);
		break;
	}


	default:
		break;
	}
}
private: System::Void fitnessFunctionComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	switch (fitnessFunctionComboBox->SelectedIndex)
	{
	case 0: {
		fitness = new RandomWeightFitness();
		gnet->setFitnessFunction(fitness);
		break;
	}


	default:
		break;
	}
}
private: System::Void reproductionSchemeComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	switch (reproductionSchemeComboBox->SelectedIndex)
	{
	case 0: {
		reproductionScheme = new GenerationalStrategies(REPRODUCTION_VARIABLE);
		gnet->setReproductionOperator(reproductionScheme);
		break;
	}


	default:
		break;
	}
}
private: System::Void parentChoiceComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	switch (parentChoiceComboBox->SelectedIndex)
	{
	case 0: {
		crossbreeding = new Panmixia(CROSSBREEDING_VARIABLE);
		gnet->setCrossbreedingOperator(crossbreeding);
		break;
	}

	case 1: {
		crossbreeding = new Inbreeding(CROSSBREEDING_VARIABLE);
		gnet->setCrossbreedingOperator(crossbreeding);
		break;
	}

	case 2: {
		crossbreeding = new Autobreeding(CROSSBREEDING_VARIABLE);
		gnet->setCrossbreedingOperator(crossbreeding);
		break;
	}

	case 3: {
		crossbreeding = new PositiveAssociativeMating(CROSSBREEDING_VARIABLE);
		gnet->setCrossbreedingOperator(crossbreeding);
		break;
	}


	default:
		break;
	}
}
private: System::Void crossbreedingTextBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

	if (e->KeyCode == Keys::Space)
	{
		CROSSBREEDING_VARIABLE = System::Convert::ToDouble(crossbreedingTextBox->Text);
		richTextBox1->AppendText("CROSSBREEDING_VARIABLE = " + CROSSBREEDING_VARIABLE + "\n");
	}
}
private: System::Void reproductionSchemeTextBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Space)
	{
		REPRODUCTION_VARIABLE = System::Convert::ToDouble(reproductionSchemeTextBox->Text);
		richTextBox1->AppendText("REPRODUCTION_VARIABLE = " + REPRODUCTION_VARIABLE + "\n");
	}
}
};
}