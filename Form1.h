#pragma once
#include<cstdlib>
#include<string>


namespace Music_To_iPhone {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 の概要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			result_ar=System::String::Empty;
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::String^ result_ar;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(2, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(239, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"iTunes起動";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(0, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"①iTunesに曲を入れる";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(0, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(241, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"②エクスプローラからコピートランスマネージャにコピー";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(2, 131);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(239, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"エクスプローラ、コピートランスマネージャ起動";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(0, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 12);
			this->label3->TabIndex = 4;
			this->label3->Text = L"- アーティストを指定";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(2, 106);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(234, 19);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(243, 156);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Music To iPhone";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				system("Movie\\pass.avi");
				system("\"C:\\Program Files (x86)\\iTunes\\iTunes.exe\"");
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				using namespace System::Diagnostics;
				using namespace System::IO;
				
				result_ar=textBox1->Text;

				if(result_ar==System::String::Empty){
					MessageBox::Show("アーティストを指定してください","Artist Frame is empty",
						MessageBoxButtons::OK,MessageBoxIcon::Warning);
					return ;
				}

				String^ command="move C:\\Users\\ /// USER NAME /// \\Desktop\\*.mp3 ";
				String^ pass="C:\\Users\\ /// USER NAME /// \\Music\\";
				command+=pass+result_ar;
				//Diagnostics::Debug::WriteLine(command);

				String^ directory=pass+result_ar;
				DirectoryInfo^ di=gcnew DirectoryInfo(directory);
				if(di->Exists){
					system((char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(command).ToPointer());
				}else{
					std::string mkdir("mkdir ");
					mkdir+=(char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(directory).ToPointer();
					system(mkdir.c_str());
					system((char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(command).ToPointer());
				}
				system("Movie\\pass.avi");
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
