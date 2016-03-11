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
		for (unsigned int i = 0; i < matr.size(); i++){
			for (unsigned int j = 0; j < matr.size(); j++)
				if (i != j && matr[i][j] != 0) {
					graph->AddEdge("D" + i, "D" + j);
				}
		}
		
		// Заполняем граф данными
		vector<NE_to_Platform> genome = gen.getGenome();

		for (unsigned int i = 0; i < genome.size(); i++){
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

	System::Windows::Forms::DataVisualization::Charting::Series^ getFillSeries(NetworkPopulation population) {
		System::Windows::Forms::DataVisualization::Charting::Series^ result = gcnew System::Windows::Forms::DataVisualization::Charting::Series();

		vector<Net> data = population.getData();

		for (Net iter : data) {
			result->Points->AddXY(iter.averageCapacity, iter.price);
		}

		return result;
	}
};