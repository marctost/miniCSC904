#include "snippet.C"

int graph_section(TString which_chamber, string which_plot, PlotterLines graphLines0, PlotterLines graphLines1, PlotterLines graphLines2, PlotterLines graphLines3, PlotterLines graphLines4, PlotterLines graphLines5, PlotterLines graphLines6, PlotterLines graphLines7, PlotterLines graphLines8, PlotterLines graphLines9, PlotterLines graphLines10);
PlotterLines resize(PlotterLines graph_line);
TGraph* make_graph(PlotterLines graph_line);
TGraph* formatting(TGraph* graph, Color_t color, float alpha, int markerstyle);

void plot_DC_HVscan(TString which_chamber, string which_plot) {
    ExcelSheet test(which_chamber+"/"+"analysis_page_darkCurrent.csv");
    
    //PlotterLines constructor args --
    //1st arg: excel spreadsheet
    //2nd arg: starting row (counts from 0)
    //3rd arg: ending row (counts from 0)
    //4th arg: column index (counts from 0)
    //5th arg: number of columns
    
    PlotterLines irr_0(test, 3, 10, 0, 2);
    PlotterLines irr_1(test, 3, 10, 5, 2);
    PlotterLines irr_2(test, 3, 10, 10, 2);
    PlotterLines irr_3(test, 3, 10, 15, 2);
    PlotterLines irr_4(test, 3, 10, 20, 2);
    PlotterLines irr_5(test, 3, 10, 25, 2);
    PlotterLines irr_6(test, 3, 10, 30, 2);
    PlotterLines irr_7(test, 3, 10, 35, 2);
    PlotterLines irr_8(test, 3, 10, 40, 2);
    PlotterLines irr_9(test, 3, 10, 45, 2);
    PlotterLines irr_10(test, 3, 10, 50, 2);
    
    PlotterLines ref_0(test, 3, 6, 2, 2);
    PlotterLines ref_1(test, 3, 6, 7, 2);
    PlotterLines ref_2(test, 3, 6, 12, 2);
    PlotterLines ref_3(test, 3, 6, 17, 2);
    PlotterLines ref_4(test, 3, 6, 22, 2);
    PlotterLines ref_5(test, 3, 6, 27, 2);
    PlotterLines ref_6(test, 3, 6, 32, 2);
    PlotterLines ref_7(test, 3, 6, 37, 2);
    PlotterLines ref_8(test, 3, 6, 42, 2);
    PlotterLines ref_9(test, 3, 6, 47, 2);
    PlotterLines ref_10(test, 3, 6, 52, 2);
    
    // When adding more runs to the plots, just make sure the values regarding length are correct, and then uncomment the right things below.
    // Choose which plot you want to make, bash script contains corresponding calls for each.
    if (which_plot=="irr"){
        graph_section(which_chamber, which_plot, irr_0, irr_1, irr_2, irr_3, irr_4, irr_5, irr_6, irr_7, irr_8, irr_9, irr_10);
    }
    else if (which_plot=="ref"){
        graph_section(which_chamber, which_plot, ref_0, ref_1, ref_2, ref_3, ref_4, ref_5, ref_6, ref_7, ref_8, ref_9, ref_10);
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

TGraph* formatting(TGraph* graph, Color_t color, float alpha, int markerstyle){
    graph->SetLineColorAlpha(color, alpha);
    graph->SetMarkerSize(1.7);
    graph->SetMarkerStyle(markerstyle);
    graph->SetMarkerColorAlpha(color, alpha);
    graph->SetLineWidth(2.0);
    return graph;
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

int graph_section(TString which_chamber, string which_plot, PlotterLines graphLines0, PlotterLines graphLines1, PlotterLines graphLines2, PlotterLines graphLines3, PlotterLines graphLines4, PlotterLines graphLines5, PlotterLines graphLines6, PlotterLines graphLines7, PlotterLines graphLines8, PlotterLines graphLines9, PlotterLines graphLines10){


    
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

//    gPad->SetLogy();

    Color_t color_irr[] = {kOrange+10, kRed+2};
    Color_t color_ref[] = {kBlue, kBlue+3};
    Color_t old_color;
    Color_t new_color;
    TString title;
    TString label;
    label = "Irradiated layer";
    old_color=color_irr[0];
    new_color=color_irr[1];
    if (which_plot=="ref"){
        label = "Reference layer";
        old_color=color_ref[0];
        new_color=color_ref[1];
    }
    title = "Dark Current: "+label;

	//the legend happens
	TLegend *legend = new TLegend(x0_l,y0_l,x1_l,y1_l,"","brNDC");
	legend->SetBorderSize(1);

    //Make sure that the vectors have the right length using the above function
    PlotterLines line_0 = resize(graphLines0);
    PlotterLines line_1 = resize(graphLines1);
    PlotterLines line_2 = resize(graphLines2);
    PlotterLines line_3 = resize(graphLines3);
    PlotterLines line_4 = resize(graphLines4);
    PlotterLines line_5 = resize(graphLines5);
    PlotterLines line_6 = resize(graphLines6);
    PlotterLines line_7 = resize(graphLines7);
    PlotterLines line_8 = resize(graphLines8);
    PlotterLines line_9 = resize(graphLines9);
    PlotterLines line_10 = resize(graphLines10);

    // This function takes the line (which has been correctly sized), and then loops through and returns graphs.
    TGraph* graph_0_ = make_graph(line_0);
    TGraph* graph_1_ = make_graph(line_1);
    TGraph* graph_2_ = make_graph(line_2);
    TGraph* graph_3_ = make_graph(line_3);
    TGraph* graph_4_ = make_graph(line_4);
    TGraph* graph_5_ = make_graph(line_5);
    TGraph* graph_6_ = make_graph(line_6);
    TGraph* graph_7_ = make_graph(line_7);
    TGraph* graph_8_ = make_graph(line_8);
    TGraph* graph_9_ = make_graph(line_9);
    TGraph* graph_10_ = make_graph(line_10);
    
    
    //This is where the lines get their colors. The last number is the transparency. THe most recent run should get the color "new_color" and a transparency of 1.
    std::vector<int> markerStyles = {20, 21, 22, 34, 43, 29, 45, 47, 33, 41, 23, 39};
    
    TGraph* graph_0 = formatting(graph_0_, old_color, 0.1, markerStyles[0]);
    TGraph* graph_1 = formatting(graph_1_, old_color, 0.2, markerStyles[1]);
    TGraph* graph_2 = formatting(graph_2_, old_color, 0.3, markerStyles[2]);
    TGraph* graph_3 = formatting(graph_3_, old_color, 0.5, markerStyles[3]);
    TGraph* graph_4 = formatting(graph_4_, old_color, 0.6, markerStyles[4]);
    TGraph* graph_5 = formatting(graph_5_, old_color, 0.7, markerStyles[5]);
    TGraph* graph_6 = formatting(graph_6_, old_color, 0.8, markerStyles[6]);
    TGraph* graph_7 = formatting(graph_7_, old_color, 0.9, markerStyles[7]);
    TGraph* graph_8 = formatting(graph_8_, new_color, 1, markerStyles[8]);
    TGraph* graph_9 = formatting(graph_9_, old_color, 1, markerStyles[9]);
    TGraph* graph_10 = formatting(graph_10_, new_color, 1, markerStyles[10]);
    
    std::vector<double> chamberDose;
    if (which_chamber.Contains("chamber5")){
        chamberDose = {0, 53, 95, 121, 149, 180, 209., 235., 316., 0., 0.};
    }
    else if (which_chamber.Contains("chamber4")){
        chamberDose = {0., 17., 26., 68., 123., 157., 188., 0., 0., 0., 0.};
    }
    else{
        chamberDose = {0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.};
    }
    
    TMultiGraph *mg = new TMultiGraph();
    // Make a multigraph to put all the stuff into and draw all at once.
    mg->Add(graph_0);
    mg->Add(graph_1);
    mg->Add(graph_2);
    mg->Add(graph_3);
    mg->Add(graph_4);
    mg->Add(graph_5);
    mg->Add(graph_6);
    mg->Add(graph_7);
    mg->Add(graph_8);
    //mg->Add(graph_9);
    //mg->Add(graph_10);
    
    // Label the legend by hand
    //chamber5
    if (which_chamber=="chamber5"){
        legend->AddEntry(graph_0, "Run 0, 0 mC/cm", "P");
        legend->AddEntry(graph_1, "Run 1, 53 mC/cm", "P");
        legend->AddEntry(graph_2, "Run 2, 95 mC/cm", "P");
        legend->AddEntry(graph_3, "Run 3, 121 mC/cm", "P");
        legend->AddEntry(graph_4, "Run 4, 149 mC/cm", "P");
        legend->AddEntry(graph_5, "Run 5, 180 mC/cm", "P");
        legend->AddEntry(graph_6, "Run 6, 209 mC/cm", "P");
        legend->AddEntry(graph_7, "Run 7, 235 mC/cm", "P");
        legend->AddEntry(graph_8, "Run 8, 316 mC/cm", "P");
//        legend->AddEntry(graph_9, "Run 9, ? mC/cm", "P");
//        legend->AddEntry(graph_10, "Run 10, ? mC/cm", "P");
        if (which_plot=="irr"){
            mg->GetYaxis()->SetRangeUser(0., 2000.);
        }
        else if (which_plot=="ref"){
            mg->GetYaxis()->SetRangeUser(0., 2000.);
        }
    }
    else if (which_chamber=="chamber4"){
        legend->AddEntry(graph_0, "Run 0, 0 mC/cm", "P");
        legend->AddEntry(graph_1, "Run 1, 17 mC/cm", "P");
        legend->AddEntry(graph_2, "Run 2, 26 mC/cm", "P");
        legend->AddEntry(graph_3, "Run 3, 68 mC/cm", "P");
        legend->AddEntry(graph_4, "Run 4, 123 mC/cm", "P");
        legend->AddEntry(graph_5, "Run 5, 157 mC/cm", "P");
        legend->AddEntry(graph_6, "Run 6, 188 mC/cm", "P");
//        legend->AddEntry(graph_7, "Run 7, ? mC/cm", "P");
//        legend->AddEntry(graph_8, "Run 8, ? mC/cm", "P");
//        legend->AddEntry(graph_9, "Run 9, ? mC/cm", "P");
//        legend->AddEntry(graph_10, "Run 10, ? mC/cm", "P");
        
        mg->GetYaxis()->SetRangeUser(0., 2000.);
    }
    
    mg->SetTitle(title);
    
    mg->Draw("ALP");
    
    // Draw and label
    mg->GetXaxis()->SetTitle("Voltage (kV)");
	mg->GetYaxis()->SetTitle("Current (pA)");
    mg->GetXaxis()->SetRangeUser(2,4);
    
	legend->Draw("SAME");


    //Save the plots
    system("mkdir -p "+which_chamber+"/"+"Plots/");
	TString saveWhere = which_chamber+"/"+"Plots/darkcurrent_"+which_plot+".pdf";
	canvas->Update();
//    canvas->SaveAs(saveWhere.c_str());
    canvas->SaveAs(saveWhere);
	canvas;

	return 0;
}
