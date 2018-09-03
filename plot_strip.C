#include "snippet.C"

int graph_section(TString which_chamber, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10);

TGraph* make_graph(TString which_chamber, int i, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10);

float Get_average_val_irr(PlotterLines run);
float Get_average_val_ref(PlotterLines run);
TGraph* format_me(TGraph* graph, Color_t color);

void plot_strip(TString which_chamber) {
    ExcelSheet test(which_chamber+"/"+"analysis_page_strip.csv");

    //PlotterLines constructor args --
    //1st arg: excel spreadsheet
    //2nd arg: starting row (counts from 0)
    //3rd arg: ending row (counts from 0)
    //4th arg: column index (counts from 0)
    //5th arg: number of columns
    
    int endingRow;
    if (which_chamber == "chamber5"){
        endingRow = 5;
    }
    else if (which_chamber == "chamber4"){
        endingRow = 9;
    }
    
    PlotterLines run_0(test, 2, endingRow, 0, 2);
    PlotterLines run_1(test, 2, endingRow, 3, 2);
    PlotterLines run_2(test, 2, endingRow, 6, 2);
    PlotterLines run_3(test, 2, endingRow, 9, 2);
    PlotterLines run_4(test, 2, endingRow, 12, 2);
    PlotterLines run_5(test, 2, endingRow, 15, 2);
    PlotterLines run_6(test, 2, endingRow, 18, 2);
    PlotterLines run_7(test, 2, endingRow, 21, 2);
    PlotterLines run_8(test, 2, endingRow, 24, 2);
    PlotterLines run_9(test, 2, endingRow, 27, 2);
    PlotterLines run_10(test, 2, endingRow, 30, 2);
    
    graph_section(which_chamber, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
}



// Makes the graphs
TGraph* make_graph(TString which_chamber, int i, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10){
    
    int numRuns = 6;
    
    std::vector<double> chamberDose;
    if (which_chamber.Contains("chamber5")){
        chamberDose = {0, 53, 95, 121, 149, 180, 209., 0., 0., 0., 0.};
    }
    else if (which_chamber.Contains("chamber4")){
        chamberDose = {0., 17., 26., 68., 123., 157., 0., 0., 0., 0., 0.};
    }
    
    TGraph *graph = new TGraph(numRuns);
    
    // Note the the first number is the "point number" and will always be 0-11,
    // the second number the accumlated charge, and the last number is the value
    graph->SetPoint(0, chamberDose[0], run_0.lines[1].at(i));
    graph->SetPoint(1, chamberDose[1], run_1.lines[1].at(i));
    graph->SetPoint(2, chamberDose[2], run_2.lines[1].at(i));
    graph->SetPoint(3, chamberDose[3], run_3.lines[1].at(i));
    graph->SetPoint(4, chamberDose[4], run_4.lines[1].at(i));
    graph->SetPoint(5, chamberDose[5], run_5.lines[1].at(i));
    //graph->SetPoint(6, chamberDose[6], run_6.lines[1].at(i));
    //graph->SetPoint(7, chamberDose[7], run_7.lines[1].at(i));
    //graph->SetPoint(8, chamberDose[8], run_8.lines[1].at(i));
    //graph->SetPoint(9, chamberDose[9], run_9.lines[1].at(i));
    //graph->SetPoint(10, chamberDose[10], run_10.lines[1].at(i));
    
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

int graph_section(TString which_chamber, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10){
    
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
//    gStyle->SetTitleAlign(13);

	//References for margin, canvas and legend
	int H = 800;
	int W = H;
	float T = 0.08*H;
	float B = 0.12*H;
	float L = 0.12*W;
	float R = 0.04*W;
    
//    float x1_l = 0.48;
//    float y1_l = 0.90;
    float x1_l = 0.96;
    float y1_l = 0.92;
	float dx_l = 0.30;
	float dy_l = 0.25;
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
    
    Color_t colors[] = {kBlue-10, kBlue-7, kBlue, kBlue+2, kAzure+4, kAzure+1, kRed, kRed+3, kRed-6, kOrange-3, kRed-3, kOrange+4, kPink, kGreen};
    
    TMultiGraph *mg = new TMultiGraph();
    
    if (which_chamber=="chamber5"){
        // This function takes the line (which has been correctly sized), and then loops through and returns graphs for the corresponding wire pair
        TGraph* graph_pair_1 = make_graph(which_chamber, 0, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_pair_2 = make_graph(which_chamber, 1, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_pair_3 = make_graph(which_chamber, 2, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_pair_4 = make_graph(which_chamber, 3, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        
        //Run the plots through the formater, select the desired colors from the list at beginning of function
        TGraph* fin_graph_pair_1 = format_me(graph_pair_1, colors[7]);
        TGraph* fin_graph_pair_2 = format_me(graph_pair_2, colors[6]);
        TGraph* fin_graph_pair_3 = format_me(graph_pair_3, colors[1]);
        TGraph* fin_graph_pair_4 = format_me(graph_pair_4, colors[2]);
        
        // Label the legend by hand
        legend->AddEntry(fin_graph_pair_1, "Wire pair 1 (irr layer) (irr)");
        legend->AddEntry(fin_graph_pair_2, "Wire pair 2 (irr layer)");
        legend->AddEntry(fin_graph_pair_3, "Wire pair 3 (ref layer)");
        legend->AddEntry(fin_graph_pair_4, "Wire pair 4 (ref layer)");
        
        // Make a multigraph to put all the stuff into and draw all at once.
        mg->Add(fin_graph_pair_1);
        mg->Add(fin_graph_pair_2);
        mg->Add(fin_graph_pair_3);
        mg->Add(fin_graph_pair_4);
    }
    else if (which_chamber=="chamber4"){
        // This function takes the line (which has been correctly sized), and then loops through and returns graphs for the corresponding wire pair
        TGraph* graph_pair_1 = make_graph(which_chamber, 0, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_pair_2 = make_graph(which_chamber, 1, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_pair_3 = make_graph(which_chamber, 2, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_pair_4 = make_graph(which_chamber, 3, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_pair_5 = make_graph(which_chamber, 4, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_pair_6 = make_graph(which_chamber, 5, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_pair_7 = make_graph(which_chamber, 6, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_pair_8 = make_graph(which_chamber, 7, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        
        //Run the plots through the formater, select the desired colors from the list at beginning of function
        TGraph* fin_graph_pair_1 = format_me(graph_pair_1, colors[0]);
        TGraph* fin_graph_pair_2 = format_me(graph_pair_2, colors[3]);
        TGraph* fin_graph_pair_3 = format_me(graph_pair_3, colors[1]);
        TGraph* fin_graph_pair_4 = format_me(graph_pair_4, colors[2]);
        TGraph* fin_graph_pair_5 = format_me(graph_pair_5, colors[7]);
        TGraph* fin_graph_pair_6 = format_me(graph_pair_6, colors[6]);
        TGraph* fin_graph_pair_7 = format_me(graph_pair_7, colors[8]);
        TGraph* fin_graph_pair_8 = format_me(graph_pair_8, colors[9]);
        
        // Label the legend by hand
        legend->AddEntry(fin_graph_pair_1, "Wire pair 1 (ref layer)");
        legend->AddEntry(fin_graph_pair_2, "Wire pair 2 (ref layer)");
        legend->AddEntry(fin_graph_pair_3, "Wire pair 3 (ref layer)");
        legend->AddEntry(fin_graph_pair_4, "Wire pair 4 (ref layer)");
        legend->AddEntry(fin_graph_pair_5, "Wire pair 5 (irr layer)");
        legend->AddEntry(fin_graph_pair_6, "Wire pair 6 (irr layer)");
        legend->AddEntry(fin_graph_pair_7, "Wire pair 7 (irr layer)");
        legend->AddEntry(fin_graph_pair_8, "Wire pair 8 (irr layer)");
        
        // Make a multigraph to put all the stuff into and draw all at once.
        mg->Add(fin_graph_pair_1);
        mg->Add(fin_graph_pair_2);
        mg->Add(fin_graph_pair_3);
        mg->Add(fin_graph_pair_4);
        mg->Add(fin_graph_pair_5);
        mg->Add(fin_graph_pair_6);
        mg->Add(fin_graph_pair_7);
        mg->Add(fin_graph_pair_8);
    }

    
    
    canvas->SetLogy();
    
    // title
    mg->SetTitle("Strip-to-Strip Resistance");
    
    mg->Draw("ALP");

    
    //  label axis
    mg->GetXaxis()->SetTitle("Accumulated charge (mC/cm)");
    mg->GetYaxis()->SetTitle("Resistance (TOhms)");
    // Set the y range so that the legend doesn't cover up any points
    mg->GetYaxis()->SetRangeUser(0.01, 1000);
	legend->Draw("SAME");

    // Locate where it goes and gets saved
    system("mkdir -p "+which_chamber+"/"+"Plots/");
    TString saveWhere = which_chamber+"/"+"Plots/strip_to_strip.pdf";
    canvas->Update();
//    canvas->SaveAs(saveWhere.c_str());
    canvas->SaveAs(saveWhere);
    canvas;

	return 0;
}
