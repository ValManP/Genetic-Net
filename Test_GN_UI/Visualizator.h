#pragma once

class Visualizator {
private:

public:
	Microsoft::Msagl::Drawing::Graph^ viewBestGenome(NetworkGeneticAlgorithm * g, NetworkDescription desc){
		
		Network n = g->gaGetBestNet(desc);
		NetworkGenome gen = g->gaGetBest();
		Microsoft::Msagl::Drawing::Graph^ graph = gcnew Microsoft::Msagl::Drawing::Graph();

		vector<vector<int>> matr = n.getNetMatrix();

		// Проставляем все ребра в графе, создавая вершины
		for (int i; i < matr.size(); i++){
			for (int j = 0; j < matr.size(); j++)
				if (i != j && matr[i][j] != 0) {
					graph->AddEdge("D" + i, "D" + j);
				}
		}
		
		// Заполняем граф данными
		vector<NE_to_Platform> genome = gen.getGenome();

		for (int i; i < genome.size(); i++){
			if (genome[i].isSet) {
				graph->FindNode("D" + genome[i].position)->Attr->Color = Microsoft::Msagl::Drawing::Color::Green;
				graph->FindNode("D" + genome[i].position)->LabelText = gcnew System::String((desc.storage[i].name + "\nCapacity ").c_str()) +desc.storage[i].capacity.ToString();
			}
		}
		
		for (int iter : n.getSwitchs()){
			if (matr[iter][iter] == 0) {
				graph->FindNode("D" + iter)->LabelText = "S" + iter;
				graph->FindNode("D" + iter)->Attr->Color = Microsoft::Msagl::Drawing::Color::Red;
			}
		}

		for (int iter : n.getUsers()){
			graph->FindNode("D" + iter)->Attr->Shape = Microsoft::Msagl::Drawing::Shape::Diamond;
			graph->FindNode("D" + iter)->LabelText = "USER #" + iter;
		}

		for (int iter : n.getRoots()){
			graph->FindNode("D" + iter)->Attr->Shape = Microsoft::Msagl::Drawing::Shape::Circle;
			graph->FindNode("D" + iter)->LabelText = "ROOT #" + iter;
		}

		return graph;
		
	}

	System::Collections::Generic::Dictionary <int, int>^ viewChart(NetworkPopulation* p){
		System::Collections::Generic::Dictionary <int, int>^ f1 = gcnew System::Collections::Generic::Dictionary<int, int>();
		vector<Net> data = p->getData();

		for (Net iter : data){
			f1->Add(iter.averageCapacity, iter.price);
		}

		return f1;
	}
};