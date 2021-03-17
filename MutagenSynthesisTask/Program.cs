using System;
using Mutagen;
using Mutagen.Bethesda.Skyrim;
using System.Linq;
using Mutagen.Bethesda;

namespace MutagenSynthesisTask
{
    class Program
    {
        static void Main(string[] args)
        {
            // ➢ Use Mutagen to extract all of the statics from a given interior scene. After that,
            // find all single form-IDs of the base model for that static, and display them in
            // an array.

            // ➢ Use Synthesis to delete all of the navmeshes from an esm/ esp file
            var pathToMod = @"D:\SteamLibrary\steamapps\common\Skyrim\Data\Skyrim.esm";
            using var mod = SkyrimMod.CreateFromBinaryOverlay(pathToMod, SkyrimRelease.SkyrimLE);
            using var state = GameEnvironment.Typical.Skyrim(SkyrimRelease.SkyrimSE);

            var cells = state.LoadOrder.PriorityOrder.Cell().WinningContextOverrides(state.LinkCache).ToList();
            var skyrimCells = state.LoadOrder.PriorityOrder.Cell().WinningContextOverrides(state.LinkCache).Where(x => x.ModKey.FileName == "Skyrim.esm").ToList();
            var firstCell = state.LoadOrder.PriorityOrder.Cell().WinningContextOverrides(state.LinkCache).First(x => x.ModKey.FileName == "Skyrim.esm");


            var statics = state.LoadOrder.PriorityOrder.Static().WinningContextOverrides(state.LinkCache).ToList();
            var aStatic = statics.First();


            var cell = cells.First(x => x.Record.EditorID == "OLDBluePalaceWing01");

            var persistent = cell.Record.Persistent.ToList();
            var temporary = cell.Record.Temporary.ToList();

            foreach(var p in persistent)
            {
                Console.WriteLine(string.Format("{0:X}", p.FormKey.ID) +  " " + p.EditorID);
            }
            foreach (var t in temporary)
            {
                Console.WriteLine(string.Format("{0:X}", t.FormKey.ID) + " " + t.EditorID);
            }

            //Gets all nav meshes in the game
            foreach (var navContext in state.LoadOrder.PriorityOrder.ANavigationMesh().WinningContextOverrides(state.LinkCache))
            {
                var navMesh = navContext.Record;

                switch (navMesh)
                {
                    case ICellNavigationMeshGetter cellNav:
                        // some code
                        Console.WriteLine("This is a cellNav " + cellNav.Data.Parent.ToString());
                        var parent = navContext.Parent;
                        if(parent.ModKey.FileName == "Skyrim.esm")
                        {
                            Console.WriteLine((parent.Record as ICellGetter).EditorID);
                        }
                        break;
                    case IWorldspaceNavigationMeshGetter worldNav:
                        Console.WriteLine("This is a worldNav");
                        // some code
                        break;
                    default:
                        throw new NotImplementedException();
                }
                //navMesh.Data.
                //var data = navMesh.Data;
                //var triangles = data.Triangles;
                //Console.WriteLine(triangles.First().Vertices.ToString());
            }


            Console.WriteLine();


            // Get scene

            // Get statics within scene

            // Display all Ids of the base model for that static


            /*
             * 
             * 
             * foreach (var navContext in state.LoadOrder.PriorityOrder.ANavigationMesh().WinningContextOverrides(state.LinkCache))
                {
                    var navMesh = navContext.Record;
                    switch (navMesh)
                    {
                        case ICellNavigationMeshGetter cellNavGetter:
                            CellNavigationMesh cellNav = (CellNavigationMesh)navContext.GetOrAddAsOverride(state.PatchMod);
                            // Clear the triangles if they exist?
                            cellNav.Data?.Triangles.Clear();
                            break;
                        case IWorldspaceNavigationMeshGetter worldNav:
                            // some code            
                            break;
                        default:
                            throw new NotImplementedException();
                    }
                }
             */
        }
    }
}
