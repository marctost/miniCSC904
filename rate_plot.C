#include "snippet.C"

int graph_section(string filename, PlotterLines graphLines);

void rate_plot(string which_plot) {
    ExcelSheet test("final_numbers_rate.csv");

    // This is the inportant bit! The first number refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. Doesn't have to be exact,
    // we have a function that makes things perfect. The 3rd number is the column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
    
    PlotterLines ALCT_no(test, 2, 27, 2, 4);
    PlotterLines CLCT_no(test, 2, 27, 7, 4);
    PlotterLines LCT_no(test, 2, 27, 12, 4);

    PlotterLines ALCT_top(test, 33, 58, 2, 4);
    PlotterLines CLCT_top(test, 33, 58, 7, 4);
    PlotterLines LCT_top(test, 33, 58, 12,4 );

    PlotterLines ALCT_bottom(test, 64, 89, 2, 4);
    PlotterLines CLCT_bottom(test, 64, 89, 7, 4);
    PlotterLines LCT_bottom(test, 64, 89, 12, 4);
    
    
    // Choose which plot you do.
    
    if (which_plot=="ALCT_no"){
        graph_section(which_plot,ALCT_no);
    }
    else if (which_plot=="ALCT_top"){
        graph_section(which_plot,ALCT_top);
    }
    else if (which_plot=="ALCT_bottom"){
        graph_section(which_plot,ALCT_bottom);
    }
    else if (which_plot=="CLCT_no"){
        graph_section(which_plot,CLCT_no);
    }
    else if (which_plot=="CLCT_top"){
        graph_section(which_plot,CLCT_top);
    }
    else if (which_plot=="CLCT_bottom"){
        graph_section(which_plot,CLCT_bottom);
    }
    else if (which_plot=="LCT_no"){
        graph_section(which_plot,LCT_no);
    }
    else if (which_plot=="LCT_top"){
        graph_section(which_plot,LCT_top);
    }
    else if (which_plot=="LCT_bottom"){
        graph_section(which_plot,LCT_bottom);
    }
}


int graph_section(string filename, PlotterLines graphLines){
	
    // These are the colors that will go into the plot.
    Color_t colors[] = {kRed, kBlue, kYellow, kCyan, kBlack};
    
    
	int number_of_points=graphLines.size;
	//Number of lines that are going to be put on the plot
    int number_of_lines=4;


	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(13);

	//References for changing margins and the size of the canvas
	int H = 800;
	int W = H;
	float T = 0.08*H;
	float B = 0.12*H;
	float L = 0.12*W;
	float R = 0.04*W;
	float x1_l = 0.38;
	float y1_l = 0.90;
	float dx_l = 0.20;
	float dy_l = 0.20;
	float x0_l = x1_l-dx_l;
	float y0_l = y1_l-dy_l;



	//make the canvas, set its properties
	TCanvas *canvas = new TCanvas("c2","c2",50,50,W,H);
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetFrameFillStyle(0);
	canvas->SetFrameBorderMode(0);
	canvas->SetLeftMargin( L/W );
	canvas->SetRightMargin( R/W );
	canvas->SetTopMargin( T/H );
	canvas->SetBottomMargin( B/H );
	canvas->cd();


	//the legend happens
	TLegend *legend = new TLegend(x0_l,y0_l,x1_l,y1_l,"","brNDC");
	legend->SetBorderSize(1);


	//loop over the various files, and the points in it
	for (int j=0; j<number_of_lines; j++){
        //Creat the graph by looping over the number of points
		TGraph *graph = new TGraph(number_of_points);
		for (int i=0; i<number_of_points; i++){
            if (graphLines.lines[j].at(i)<0){
                graph->SetPoint(i, graphLines.voltages.at(i),0);
            }
            else{
                graph->SetPoint(i,graphLines.voltages.at(i),graphLines.lines[j].at(i));
			}
        }

        // Some maintanence and labeling for the plot.
		graph->GetXaxis()->SetTitle("Voltage (kV)");
		graph->GetYaxis()->SetTitle("Hertz");
		graph->SetLineColor(colors[j]);
		graph->SetLineWidth(2.0);
        string hello = "Run ";
        string name_thing = hello+to_string(j);
        char const *name = name_thing.c_str();
		legend->AddEntry(graph, name);
		graph->SetMaximum(450);
        graph->GetXaxis()->SetRangeUser(2,4);
        
        //Some things that can be fussed with
        graph->SetMarkerStyle(20);
        graph->SetMarkerSize(0.8);
        graph->SetMarkerColor(colors[j]);
        
        // Draw the plots
        if (j==0){
            graph->SetTitle(filename.c_str());
			graph->Draw();
		}
		else{
        
			graph->Draw("SAME P L");
		}


	}

	legend->Draw("SAME");

    // Save the plot to the desktop.
	string saveWhere = "/Users/marctost/Desktop/"+filename+".png";
	canvas->Update();
	canvas->SaveAs(saveWhere.c_str());
    //canvas->Print(filename+".png");
	canvas;


	return 0;
}
