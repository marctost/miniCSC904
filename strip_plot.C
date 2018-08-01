#include "snippet.C"

int graph_section(PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10);
TGraph* make_graph(int i, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10);
float Get_average_val_irr(PlotterLines run);
float Get_average_val_ref(PlotterLines run);
TGraph* format_me(TGraph* graph, Color_t color);

void strip_plot() {
    ExcelSheet test("analysis_page_strip.csv");

    // This is the important bit! The first value refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. Doesn't have to be exact,
    // we have a function that makes things perfect. The 3rd number is the column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
    
    PlotterLines run_0(test, 2, 5, 0, 2);
    PlotterLines run_1(test, 2, 5, 3, 2);
    PlotterLines run_2(test, 2, 5, 6, 2);
    PlotterLines run_3(test, 2, 5, 9, 2);
    PlotterLines run_4(test, 2, 5, 12, 2);
    PlotterLines run_5(test, 2, 5, 15, 2);
    PlotterLines run_6(test, 2, 5, 18, 2);
    PlotterLines run_7(test, 2, 5, 21, 2);
    PlotterLines run_8(test, 2, 5, 24, 2);
    PlotterLines run_9(test, 2, 5, 27, 2);
    PlotterLines run_10(test, 2, 5, 30, 2);
    
    graph_section(run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
}



// Makes the graphs
TGraph* make_graph(int i, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10){
    TGraph *graph = new TGraph(6);
    
    // Creating the TGraph and filling it with 5 points (number of runs)
    // The first number is the "point number" and will always be 0-4. the second number is x-axis, which is the accumulated charge, and has to be entered by hand. The last number is charge mean, where the at(i) refers to which wire pair is currently being looked at

    graph->SetPoint(0, 0, run_0.lines[1].at(i));
    graph->SetPoint(1, 53, run_1.lines[1].at(i));
    graph->SetPoint(2, 95, run_2.lines[1].at(i));
    graph->SetPoint(3, 121, run_3.lines[1].at(i));
    graph->SetPoint(4, 149, run_4.lines[1].at(i));
    graph->SetPoint(5, 180, run_5.lines[1].at(i));
    //graph->SetPoint(5, 200, run_6.lines[1].at(i));
    //graph->SetPoint(5, 205, run_7.lines[1].at(i));
    //graph->SetPoint(5, 210, run_8.lines[1].at(i));
    //graph->SetPoint(5, 220, run_9.lines[1].at(i));
    //graph->SetPoint(5, 230, run_10.lines[1].at(i));
    
    
    return graph;
}

// Sets the marker style and coloring for each graph
TGraph* format_me(TGraph* graph, Color_t color){
    graph->SetLineColor(color);
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerColor(color);
    graph->SetLineWidth(2.0);
    
    return graph;
}



int graph_section(PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10){
	
    // For this plot, the "i" in graphLine.line[thing].at(i) refers to the wire pair being used,
    // following the formula i+1 i.e. at(0) is pair 1, etc
    
    
    Color_t colors[] = {kBlue-10, kBlue-7, kBlue, kBlue+2, kAzure+4, kAzure+1, kRed, kRed+3, kRed-6, kOrange-3, kRed-3, kOrange+4, kPink, kGreen};
    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(13);

	//References for margin, canvas and legend
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
    
    // This function takes the line (which has been correctly sized), and then loops through and returns graphs for the corresponding wire pair
    TGraph* graph_pair_1 = make_graph(0,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
    TGraph* graph_pair_2 = make_graph(1,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
    TGraph* graph_pair_3 = make_graph(2,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
    TGraph* graph_pair_4 = make_graph(3,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
    
    
    //Run the plots through the formater, select the desired colors from the list at beginning of function
    TGraph* fin_graph_pair_1 = format_me(graph_pair_1, colors[6]);
    TGraph* fin_graph_pair_2 = format_me(graph_pair_2, colors[7]);
    TGraph* fin_graph_pair_3 = format_me(graph_pair_3, colors[1]);
    TGraph* fin_graph_pair_4 = format_me(graph_pair_4, colors[2]);
    
    // Label the legend by hand
    legend->AddEntry(fin_graph_pair_1, "Wire pair 1 (irr layer) (irr)");
    legend->AddEntry(fin_graph_pair_2, "Wire pair 2 (irr layer)");
    legend->AddEntry(fin_graph_pair_3, "Wire pair 3 (ref)");
    legend->AddEntry(fin_graph_pair_4, "Wire pair 4 (ref)");

    
    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    mg->Add(fin_graph_pair_1);
    mg->Add(fin_graph_pair_2);
    mg->Add(fin_graph_pair_3);
    mg->Add(fin_graph_pair_4);
    
    canvas->SetLogy();
    
    // title
    mg->SetTitle("Strip to strip");
    
    mg->Draw("ALP");

    
    //  label axis
    mg->GetXaxis()->SetTitle("Accumulated charge (mC/cm)");
    mg->GetYaxis()->SetTitle("Resistance (TOhms)");
    // Set the y range so that the legend doesn't cover up any points
    mg->GetYaxis()->SetRangeUser(0.05, 220);
	legend->Draw("SAME");

    
    
    // Locate where it goes and gets saved
	string saveWhere = "/Users/marctost/Desktop/strip_to_strip.png";
	canvas->Update();
	canvas->SaveAs(saveWhere.c_str());
	canvas;

	return 0;
}
