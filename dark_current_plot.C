#include "snippet.C"

int graph_section(string filename, PlotterLines graphLines0, PlotterLines graphLines1, PlotterLines graphLines2, PlotterLines graphLines3, PlotterLines graphLines4);
PlotterLines resize(PlotterLines graph_line);
TGraph* make_graph(PlotterLines graph_line);

void dark_current_plot(string which_plot) {
    ExcelSheet test("analysis_page_darkCurrent.csv");

    
    // This is the inportant bit! The first value refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. The 3rd number is the first column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
    
    PlotterLines irr_0(test, 3, 10, 0, 2);
    PlotterLines ref_0(test, 3, 6, 3, 2);
    
    PlotterLines irr_1(test, 3, 9, 7, 2);
    PlotterLines ref_1(test, 3, 6, 10, 2);
    
    PlotterLines irr_2(test, 3, 10, 14, 2);
    PlotterLines ref_2(test, 3, 6, 17, 2);
    
    PlotterLines irr_3(test, 3, 10, 21, 2);
    PlotterLines ref_3(test, 3, 6, 24, 2);
    
    PlotterLines irr_4(test, 3, 10, 28, 2);
    PlotterLines ref_4(test, 3, 6, 31, 2);

    
    // Choose which plot you want to make, bash script contains corresponding calls for each.
    if (which_plot=="irr"){
        graph_section(which_plot,irr_0, irr_1, irr_2, irr_3, irr_4);
    }
    else if (which_plot=="ref"){
        graph_section(which_plot,ref_0, ref_1, ref_2, ref_3, ref_4);
    }

}

// This function makes sure that all the vectors are the right length, and that there are not extra values floating around.
PlotterLines resize(PlotterLines graph_line){
    for (int g=graph_line.lines[0].size()-1; g>0; g=g-1){
        if (graph_line.lines[0].at(g)==graph_line.lines[0].at(g-1)){
            graph_line.lines[0].pop_back();
            graph_line.lines[1].pop_back();
        }
        else{
            continue;
        }
    }
    return graph_line;
}


// Creates the graphs themselves. TGraph constructor takes the size of the vector as an argument, and then each point is filled.
TGraph* make_graph(PlotterLines graph_line){
    TGraph *graph = new TGraph(graph_line.lines[0].size());
    for (int i=0; i<graph_line.lines[0].size(); i++){
        // The SetPoint function takes (i, x, y) as its arguments, so here it can be seen that side-by-side pairs in the excel document are put into each line.
        graph->SetPoint(i,graph_line.lines[0].at(i), graph_line.lines[1].at(i));
    }
    return graph;
}


int graph_section(string filename, PlotterLines graphLines0, PlotterLines graphLines1, PlotterLines graphLines2, PlotterLines graphLines3, PlotterLines graphLines4){
    
    TString title;
    TString label;
    label = "Irradiated layer";
    // This variable "color counter" is bumped up to 5 when the reference layer is called, in order to plot the different layers in different colors.
    int color_counter=0;

    // If statements control the title of the graph
    if (filename=="ref"){
        color_counter=5;
        label = "Reference layer";
    }
    title = "Dark Current, "+label;

    // Colors used, irradiated first and then reference layer colors
    Color_t colors[] = {kRed-10, kRed-7, kRed, kRed+2, kRed+4, kBlue-10, kBlue-7, kBlue, kBlue+1, kBlue+4};
    
    //Make sure that the vectors have the right length using the above function
    PlotterLines line_0 = resize(graphLines0);
    PlotterLines line_1 = resize(graphLines1);
    PlotterLines line_2 = resize(graphLines2);
    PlotterLines line_3 = resize(graphLines3);
    PlotterLines line_4 = resize(graphLines4);
    
    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(23);

	//References for margins, canvas and the legend
	int H = 800;
	int W = H;
	float T = 0.08*H;
	float B = 0.12*H;
	float L = 0.12*W;
	float R = 0.04*W;
	float x1_l = 0.48;
	float y1_l = 0.90;
	float dx_l = 0.30;
	float dy_l = 0.30;
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

    // This function takes the line (which has been correctly sized), and then loops through and returns graphs.
    TGraph* graph_0 = make_graph(line_0);
    TGraph* graph_1 = make_graph(line_1);
    TGraph* graph_2 = make_graph(line_2);
    TGraph* graph_3 = make_graph(line_3);
    TGraph* graph_4 = make_graph(line_4);
    
    // Sets the colors of each graph that has been created above
    graph_0->SetLineColor(colors[0+color_counter]);
    graph_1->SetLineColor(colors[1+color_counter]);
    graph_2->SetLineColor(colors[2+color_counter]);
    graph_3->SetLineColor(colors[3+color_counter]);
    graph_4->SetLineColor(colors[4+color_counter]);
    
    // Marker style
    graph_0->SetMarkerStyle(20);
    graph_0->SetMarkerSize(0.8);
    graph_0->SetMarkerColor(colors[0+color_counter]);
    graph_1->SetMarkerStyle(20);
    graph_1->SetMarkerSize(0.8);
    graph_1->SetMarkerColor(colors[1+color_counter]);
    graph_2->SetMarkerStyle(20);
    graph_2->SetMarkerSize(0.8);
    graph_2->SetMarkerColor(colors[2+color_counter]);
    graph_3->SetMarkerStyle(20);
    graph_3->SetMarkerSize(0.8);
    graph_3->SetMarkerColor(colors[3+color_counter]);
    graph_4->SetMarkerStyle(20);
    graph_4->SetMarkerSize(0.8);
    graph_4->SetMarkerColor(colors[4+color_counter]);
    
    //More formatting
    graph_0->SetLineWidth(2.0);
    graph_1->SetLineWidth(2.0);
    graph_2->SetLineWidth(2.0);
    graph_3->SetLineWidth(2.0);
    graph_4->SetLineWidth(2.0);
    
    // Label the legend by hand
    legend->AddEntry(graph_0, "Run 0, 0 mC/cm");
    legend->AddEntry(graph_1, "Run 1, 53 mC/cm");
    legend->AddEntry(graph_2, "Run 2, 95 mC/cm");
    legend->AddEntry(graph_3, "Run 3, 121 mC/cm");
    legend->AddEntry(graph_4, "Run 4, 149 mC/cm");

    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    mg->Add(graph_0);
    mg->Add(graph_1);
    mg->Add(graph_2);
    mg->Add(graph_3);
    mg->Add(graph_4);
    
    mg->SetTitle(title);
    
    mg->Draw("ALP");
    
    // Draw and label
    mg->GetXaxis()->SetTitle("Voltage (kV)");
	mg->GetYaxis()->SetTitle("Current (pA)");
    mg->GetXaxis()->SetRangeUser(2,4);
    
    

	legend->Draw("SAME");

    // Locate where it goes and gets saved, may have to be changed.
	string saveWhere = "/Users/marctost/Desktop/darkcurrent_"+filename+".png";
	canvas->Update();
	canvas->SaveAs(saveWhere.c_str());
	canvas;

	return 0;
}
